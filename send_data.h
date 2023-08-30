#include <HTTPClient.h>  //Board = Version 2.7.4
#include <ArduinoJson.h> //Library = arduinoJson 6.15.1

String nama_alat;
String id_alat;

byte server[] = {103, 117, 57, 130};
WiFiClient client;
const int httpPort = 80;
String url;
unsigned long timeout;

void sendData(){
  
  if(nomor_akuarium == 1){
  nama_alat = "Akuarium 1";
  id_alat = "99fc3e74-66a1-4cb7-8d65-5b30d3bfe764";
  }

  if(nomor_akuarium == 2){
    nama_alat = "Akuarium 2";
    id_alat = "99fc8849-9406-48cb-95fb-be45a76a45cb";
  }

  if(nomor_akuarium == 3){
    nama_alat = "Akuarium 3";
    id_alat = "99fd53a8-a7ea-47ae-932d-3f6565335154";
  }

  if(nomor_akuarium == 4){
    nama_alat = "Akuarium 4";
    id_alat = "99fd53cc-a142-4ef2-8815-dbb7ce626d2e";
  }

  if(nomor_akuarium == 5){
    nama_alat = "Akuarium 5";
    id_alat = "99fd53d8-746b-443d-abc4-f0e8213391ea";
  }

  if(nomor_akuarium == 6){
    nama_alat = "Akuarium 6";
    id_alat = "99fd53e5-7493-497d-950d-c7d9e2bca76b";
  }

  float suhu = value_temperature;
  float ph = value_ph;
  float amonia = value_mq_ppm;
  float tss = value_tss;
  float tds = value_tds;
  float salinitas = value_salinity;
  // Serial.println(suhu);
  // Serial.println(ph);
  // Serial.println(amonia);
  // Serial.println(tss);
  // Serial.println(tds);
  // Serial.println(salinitas);
  
 String url = "http://simonair.my.id/api/monitoring/" +
               String(id_alat) + "/" +
               String(ph) + "/" +
               String(suhu) + "/" +
               String(amonia) + "/" +
               String(tss) + "/" +
               String(tds) + "/" +
               String(salinitas);

  // Mengirim HTTP GET request ke server
  HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();
  if (httpResponseCode == HTTP_CODE_OK) {
    String response = http.getString();
    Serial.println("Data berhasil dikirim");
    Serial.println("Response: " + response);
  } else {
    Serial.print("HTTP Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();

} 

void sendDataVoltage(){

  if(nomor_akuarium == 1){
    nama_alat = "Akuarium 1";
    id_alat = "mY6cSeR2Cj0L";
  }

  if(nomor_akuarium == 2){
    nama_alat = "Akuarium 2";
    id_alat = "nxSmsSXTyf36";
  }

  if(nomor_akuarium == 3){
    nama_alat = "Akuarium 3";
    id_alat = "zrKht1cq5fPL";
  }

  if(nomor_akuarium == 4){
    nama_alat = "Akuarium 4";
    id_alat = "dripROD0IdEl";
  }

  if(nomor_akuarium == 5){
    nama_alat = "Akuarium 5";
    id_alat = "kn85wb47rdmD";
  }

  if(nomor_akuarium == 6){
    nama_alat = "Akuarium 6";
    id_alat = "mljxTvTevUAr";
  }


  float volt_ph = voltage_ph;
  float volt_tds = voltage_tds;
  float volt_tss = voltage_tss;
  float volt_amonia = voltage_mq;
  // Serial.println(ph);
  // Serial.println(tds);
  // Serial.println(tss);
  // Serial.println(amonia);
 String url_voltage = "http://simonair.my.id/api/monitoring/voltage" +
               String(id_alat) + "/" +
               nama_alat + "/" +
               String(volt_ph) + "/" +
               "0" + "/" +
               String(volt_amonia) + "/" +
               String(volt_tss) + "/" +
               String(volt_tds) + "/" +
               "0";

  // Mengirim HTTP GET request ke server
  HTTPClient http_voltage;
  http_voltage.begin(url_voltage);

  int httpResponseCode = http_voltage.GET();
  if (httpResponseCode == HTTP_CODE_OK) {
    String response = http_voltage.getString();
    Serial.println("Data berhasil dikirim");
    Serial.println("Response: " + response);
  } else {
    Serial.print("HTTP Error code: ");
    Serial.println(httpResponseCode);
  }

  http_voltage.end();

} 