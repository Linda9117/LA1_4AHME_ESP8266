#include <Arduino.h>

#include "esp8266comport.h"
#include "cli.h"
#include "cmd.h"
#include "esp8266_wifi.h"

CliComPort *uart0 = NULL;
CliComPort *tcp = NULL;

#define SSID "LA1"
#define PWD "LA123456"

void setup() {
  cliCreateComPort(&uart0, esp8266comportCreateSerialTx(0, 76800));
  cliAddComPort(uart0);
  cliCreateComPort(&tcp, esp8266comportCreateWiFiTcpSocketTx(SSID,PWD, 23));
  cliAddComPort(tcp);
  
  cliPrintf(uart0,"Connecting to Wifi: %s ...", SSID);
  if(esp8266wifiConnect(SSID,PWD)){
    cliPrintf(uart0, "Wifi Connected to: %s", WiFi.localIP().toString().c_str());
  }else{
    cliPrintf(uart0, "Wifi is not connected!");}

  cliPrintPrompt(uart0, TXT_CYAN);
  cliPrintPrompt(uart0, TXT_GREEN);
}

void loop() {

  if(esp8266comportWiFiTcpSocketCheckConnection(tcp) == COMPORT_RECONNECTED){
    cliClearScreen(tcp);
    cliPrintPrompt(tcp,TXT_RED);
  }
  
  if (cliHasInput(uart0)) {
    cliReceiveByte(uart0);
  }

  if(cliHasInput(tcp))
    cliReceiveByte(tcp);

  if (cliProcessRxData(uart0)) {
    cmdExecuteCommand(uart0);
    cliPrintPrompt(uart0, TXT_GREEN);
  }

  if(cliProcessRxData(tcp)){
    cmdExecuteCommand(tcp);
    cliPrintPrompt(tcp, TXT_GREEN);
  }
}