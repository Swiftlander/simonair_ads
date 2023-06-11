#include <HTTPClient.h>  //Board = Version 2.7.4
#include <ArduinoJson.h> //Library = arduinoJson 6.15.1

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

#include <WebSerial.h>


// ====================================================
// KONFIGURASI OTA UPDATE | START
// ====================================================
 AsyncWebServer serverOTA(80);
// ====================================================
// KONFIGURASI OTA UPDATE | END
// ====================================================

void setup_ota_serial_web(){
    AsyncElegantOTA.begin(&serverOTA);
    WebSerial.begin(&serverOTA);
    serverOTA.begin();
}

void ph_value_print_to_web_serial(){
  WebSerial.println("============== PH ==============");
  WebSerial.print("ADC PH: ");
  WebSerial.println(adc0_ph);
  WebSerial.print("Voltage PH: ");
  WebSerial.println(ads.computeVolts(adc0_ph));
  WebSerial.print("Nilai PH: ");
  WebSerial.println(value_ph);
  WebSerial.println();
}

void tds_value_print_to_web_serial(){
  WebSerial.println("============== TDS ==============");
  WebSerial.print("ADC TDS: ");
  WebSerial.println(adc1_tds);
  WebSerial.print("Voltage TDS: ");
  WebSerial.println(ads.computeVolts(adc1_tds));
  WebSerial.print("TDS Value: ");
  WebSerial.print(raw_value_tds);
  WebSerial.println("ppm");
  WebSerial.println();
}

void tss_value_print_to_web_serial(){
  WebSerial.println("============== TSS/TURBIDITY ==============");
  WebSerial.print("ADC TSS/TURBIDITY: ");
  WebSerial.println(raw_adc_tss);
  WebSerial.print("Voltage TSS/TURBIDITY: ");
  WebSerial.println(ads.computeVolts(adc2_tss));
  WebSerial.print("Nilai TURBIDITY: ");
  WebSerial.println(value_mq_ppm);
  WebSerial.println();
}

void temperature_value_print_to_web_serial(){
  WebSerial.println("============== TEMPERATURE ==============");
  WebSerial.print("Nilai Suhu: ");
  WebSerial.println(value_temperature);
  WebSerial.println();
}

void mq_value_print_to_web_serial(){
  WebSerial.println("============== MQ ==============");
  WebSerial.print("ADC MQ: ");
  WebSerial.println(adc3_mq);
  WebSerial.print("Voltage MQ: ");
  WebSerial.println(ads.computeVolts(adc3_mq));
  WebSerial.print("Nilai MQ: ");
  WebSerial.println(value_mq_ppm);
  WebSerial.println();
}

void salinity_value_print_to_web_serial(){
  WebSerial.println("============== Salinity ==============");
  WebSerial.print("ADC Salinity: ");
  WebSerial.println(adc1_tds);
  WebSerial.print("Voltage salinity: ");
  WebSerial.println(ads.computeVolts(adc1_tds));
  WebSerial.print("Nilai salinity: ");
  WebSerial.println(value_salinity);
  WebSerial.println();
}





