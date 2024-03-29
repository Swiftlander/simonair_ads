// ====================================================
// WIFI
// ====================================================
#include <WiFi.h>

// ======== WIFI 1 ========
// const char* ssid = "Acer";
// const char* password = "1029384756";

// IPAddress local_IP(192,168,137,100);
// IPAddress gateway(192,168,137,1);
// IPAddress subnet(255, 255, 255, 0);
// IPAddress primaryDNS(8, 8, 8, 8);
// IPAddress secondaryDNS(8, 8, 4, 4);
// ======== WIFI 1 ========


// ======== WIFI 2 ========
const char* ssid = "Canon-Pixma-E460";
const char* password = "Ikanlele1kilo";

String ip_address;
IPAddress local_IP;
IPAddress gateway(172, 22, 38, 254);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);
// ======== WIFI 2 ========


void initWiFi() {

  if(nomor_akuarium == 1){
    ip_address = "172.22.38.11";
    local_IP.fromString(ip_address.c_str());
  }

  if(nomor_akuarium == 2){
    ip_address = "172.22.38.12";
    local_IP.fromString(ip_address.c_str());
  }

  if(nomor_akuarium == 3){
    ip_address = "172.22.38.13";
    local_IP.fromString(ip_address.c_str());
  }
  
  if(nomor_akuarium == 4){
    ip_address = "172.22.38.14";
    local_IP.fromString(ip_address.c_str());
  }
  
  if(nomor_akuarium == 5){
    ip_address = "172.22.38.15";
    local_IP.fromString(ip_address.c_str());
  }

  if(nomor_akuarium == 6){
    ip_address = "172.22.38.16";
    local_IP.fromString(ip_address.c_str());
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  
  Serial.println("Connecting to WiFi ..");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    Serial.println("\nConnecting..");
    digitalWrite(indikator, LOW);
    delay(1000);
    digitalWrite(indikator, HIGH);
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED)
   {
    Serial.println("Connected!!!");
    digitalWrite(indikator, HIGH);
    Serial.println(WiFi.localIP());
    delay(1000);
   }
}
