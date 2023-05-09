
#include <DallasTemperature.h> // Library Sensor Suhu
#include <OneWire.h> // Library Sensor Suhu

#include <HTTPClient.h>  //Board = Version 2.7.4
#include <ArduinoJson.h> //Library = arduinoJson 6.15.1

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

#include <WebSerial.h>

// JUMLAH PENGAMBILAN SAMPEL
#define SAMPLE_VALUE 50

#include "ads_setup.h"

#include "temperature_sensor.h"
#include "tds_sensor.h"
#include "ph_sensor.h"
#include "tss_turbidity_sensor.h"
#include "mq_sensor.h"
#include "salinity_sensor.h"

#include "OTAandSerialWeb.h"
#include "send_data.h"

#include "wifi_conf.h"

// ====================================================
// KONFIGURASI LED INTERNAL | START
// ====================================================
int indikator = LED_BUILTIN;
// ====================================================
// KONFIGURASI LED INTERNAL | END
// ====================================================

// INTERVAL PEMBACAAN
unsigned long intervalSendTime = 30000;
unsigned long prevCurrentTimeSend = 0;
unsigned long intervalPrintTime = 3000;
unsigned long prevCurrentTimePrint = 0;
unsigned long intervalSendDataTime = 15000;
unsigned long prevCurrentTimeSendData = 0;

void setup(){
    Serial.begin(115200);
    
    // initWiFi();
    // setup_ota_serial_web();
    setup_ads();
}

void loop(){
    
  unsigned long currentTime = millis();

  // temperatureSensorFunction();
  // phSensor();
  tdsSensor();
  // tssTurbiditySensor();
  // salinitySensor();
  // mqSensor();
    

    if(currentTime - prevCurrentTimePrint >= intervalPrintTime){
      
      // temperaturePrintToSerialMonitor();
      // phPrintToSerialMonitor();
      // tssPrintToSerialMonitor();
      tdsPrintToSerialMonitor();
      // mqPrintToSerialMonitor();
      // salinityPrintToSerialMonitor();

      // ph_value_print_to_web_serial();
      // tds_value_print_to_web_serial();
      // tss_value_print_to_web_serial();
      // mq_value_print_to_web_serial();

      prevCurrentTimePrint = currentTime;
    }
  
  // if(currentTime - prevCurrentTimeSendData >= intervalSendDataTime){
  //   sendData();
  //   prevCurrentTimeSendData = currentTime;
  // }     
    
}
