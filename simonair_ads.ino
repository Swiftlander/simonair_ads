  // JUMLAH PENGAMBILAN SAMPEL
  #define SAMPLE_VALUE 50

  // Hanya support akuarium 1 sampai 6
  const int nomor_akuarium = 6;

// ====================================================
// KONFIGURASI LED INTERNAL | START
// ====================================================
int indikator = LED_BUILTIN;
// int indikator = 2;
// ====================================================
// KONFIGURASI LED INTERNAL | END
// ====================================================


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

// INTERVAL PEMBACAAN
unsigned long intervalSendTime = 15000;
unsigned long prevCurrentTimeSend = 0;
unsigned long intervalPrintTime = 5000;
unsigned long prevCurrentTimePrint = 0;
unsigned long intervalSendDataTime = 20000;
unsigned long prevCurrentTimeSendData = 0;

void setup(){
    Serial.begin(115200);
  
    setup_ads();
    pinMode(indikator, OUTPUT); 
}

void loop(){
  
  unsigned long currentTime = millis();

  if (WiFi.status() != WL_CONNECTED){
      initWiFi();
      delay(3000);
      setup_ota_serial_web();
  }

  temperatureSensorFunction();
  phSensor();
  tdsSensor();
  tssTurbiditySensor();
  salinitySensor();
  
  readMQ();
  // searchROMQ();
  // mqSensor();
    

    if(currentTime - prevCurrentTimePrint >= intervalPrintTime){
      
      temperaturePrintToSerialMonitor();
      phPrintToSerialMonitor();
      tdsPrintToSerialMonitor();
      salinityPrintToSerialMonitor();
      tssPrintToSerialMonitor();
      mqPrintToSerialMonitor();

      ph_value_print_to_web_serial();
      tds_value_print_to_web_serial();
      temperature_value_print_to_web_serial();
      salinity_value_print_to_web_serial();
      tss_value_print_to_web_serial();
      mq_value_print_to_web_serial();

      prevCurrentTimePrint = currentTime;
    }
  
  if(currentTime - prevCurrentTimeSendData >= intervalSendDataTime){
    if (WiFi.status() == WL_CONNECTED){
      sendData();
      sendDataVoltage();
    }
    prevCurrentTimeSendData = currentTime;
  }     
    
}
