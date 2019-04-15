//
// Created by djcopley on 4/5/19.
//

#include "RF24Logger.h"

RF24Logger::RF24Logger(LOG_LEVEL maxLogLevel, String formatter, uint8_t cepin, uint8_t cspin) : LoggerBase(maxLogLevel, formatter)
{
    radio = new RF24(cepin, cspin);
    radio->begin();
    radio->setChannel(1);
    radio->setPALevel(RF24_PA_MAX);
    radio->setDataRate(RF24_250KBPS);
    radio->setAutoAck(1);
    radio->setPayloadSize(sizeof(char));

    radio->setCRCLength(RF24_CRC_8);
    radio->openWritingPipe(pipes[0]);
    radio->openReadingPipe(1, pipes[1]);

    radio->startListening();
    radio->powerUp();
}

void RF24Logger::logMessage(LOG_LEVEL msgLogLevel, String message)
{
    if (isMsgLoggable(msgLogLevel)) {
        for (int idx = 0; idx < message.length(); idx++) {
            radio->write(new char(message.charAt(idx)), sizeof(char));
        }
        radio->write(new char('\n'), sizeof(char)); // Newline character
    }
}
