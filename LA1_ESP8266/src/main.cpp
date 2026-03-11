#include <Arduino.h>

#include "esp8266comport.h"
#include "cli.h"


CliComPort *uart0 = NULL;

void setup() {
  cliCreateComPort(&uart0, esp8266comportCreateSerialTx(0, 76800));
  cliAddComPort(uart0);

  cliPrintPrompt(uart0, TXT_GREEN);
}

void loop() {
  if (cliHasInput(uart0)) {
    cliReceiveByte(uart0);
  }

  if (cliProcessRxData(uart0)) {
    cliPrintPrompt(uart0, TXT_GREEN);
  }
}