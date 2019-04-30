//
// Created by djcopley on 4/5/19.
//

#include "RF24Logger.h"

RF24Logger::RF24Logger(LOG_LEVEL maxLogLevel, String formatter, uint8_t cepin, uint8_t cspin) : LoggerBase(maxLogLevel, formatter)
{
    radio = new RF24(cepin, cspin);
    radio->begin();

    radio->setDataRate(RF24_250KBPS);
    radio->setPALevel(RF24_PA_MAX);
    radio->setChannel(70);

    radio->enableDynamicPayloads();
    radio->setRetries(15, 15);
    radio->setCRCLength(RF24_CRC_16);

    radio->openWritingPipe(pipes[0]);
    radio->openReadingPipe(1, pipes[1]);

    radio->startListening();
}

void RF24Logger::generateMessage(String message)
{
    char *cString = message.c_str();
    for (int i = 0; i < message.length(); i++) {
        char incomingByte = cString[i];

        if (stringOverflow) {
            serialBuffer[dataBufferIndex++] = charOverflow;  // Place saved overflow byte into buffer
            serialBuffer[dataBufferIndex++] = incomingByte;  // saved next byte into next buffer
            stringOverflow = false;                          // turn overflow flag off
        } else if (dataBufferIndex > 31) {
            stringComplete = true;        // Send this buffer out to radio
            stringOverflow = true;        // trigger the overflow flag
            charOverflow = incomingByte;  // Saved the overflow byte for next loop
            dataBufferIndex = 0;          // reset the buffer index
            break;
        } else if (incomingByte == '\n') {
            serialBuffer[dataBufferIndex] = 0;
            stringComplete = true;
        } else {
            serialBuffer[dataBufferIndex++] = incomingByte;
            serialBuffer[dataBufferIndex] = 0;
        }
    }
}

void RF24Logger::logMessage(LOG_LEVEL msgLogLevel, String message)
{
    if (isMsgLoggable(msgLogLevel)) {

        generateMessage(message);

        strcat(SendPayload, serialBuffer);

        // swap TX & Rx addr for writing
        radio->openWritingPipe(pipes[1]);
        radio->openReadingPipe(0, pipes[0]);
        radio->stopListening();
        radio->write(&SendPayload, strlen(SendPayload));

        // String complete
        stringComplete = false;

        // restore TX & Rx addr for reading
        radio->openWritingPipe(pipes[0]);
        radio->openReadingPipe(1, pipes[1]);
        radio->startListening();
        SendPayload[0] = 0;
        dataBufferIndex = 0;
    }
}
