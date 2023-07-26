#include <HTTPClient.h>  //Board = Version 2.7.4
#include <ArduinoJson.h> //Library = arduinoJson 6.15.1

// Akuarium 1 = mY6cSeR2Cj0L
// AKuarium 2 = nxSmsSXTyf36
// Akuarium 3 = zrKht1cq5fPL
// Akuarium 4 = dripROD0IdEl
// Akuarium 5 = kn85wb47rdmD
// Akuarium 6 = mljxTvTevUAr

String nama_alat = "Akuarium 2";
const String id_alat = "nxSmsSXTyf36";

byte server[] = {103, 117, 57, 130};
WiFiClient client;
const int httpPort = 80;
String url;
unsigned long timeout;

void sendData(){

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
 String url = "http://103.117.57.130/api/monitoring/" +
               String(id_alat) + "/" +
               nama_alat + "/" +
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

    float volt_ph = voltage_ph;
    float volt_tds = voltage_tds;
    float volt_tss = voltage_tss;
    float volt_amonia = voltage_mq;
    // Serial.println(ph);
    // Serial.println(tds);
    // Serial.println(tss);
    // Serial.println(amonia);
 String url_voltage = "http://simonair.portalsvipb.com/api/monitoring/" +
               String(id_alat) + "/" +
               nama_alat + "/" +
               String(volt_ph) + "/" +
               String(volt_tds) + "/" +
               String(volt_tss) + "/" +
               String(volt_amonia);

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