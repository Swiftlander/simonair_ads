#include <HTTPClient.h>  //Board = Version 2.7.4
#include <ArduinoJson.h> //Library = arduinoJson 6.15.1

// Akuarium 1 = mY6cSeR2Cj0L
// AKuarium 2 = nxSmsSXTyf36
// Akuarium 3 = zrKht1cq5fPL
// Akuarium 4 = dripROD0IdEl
// Akuarium 5 = kn85wb47rdmD
// Akuarium 6 = mljxTvTevUAr

String nama_alat = "Akuarium 3";
const String id_alat = "zrKht1cq5fPL";

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
