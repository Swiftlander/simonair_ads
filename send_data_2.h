#include <HTTPClient.h>  //Board = Version 2.7.4
#include <ArduinoJson.h> //Library = arduinoJson 6.15.1

const char *nama = "Aquarium_5";
const String id_alat = "5Z0SPeQnezqL";

byte server[] = {103, 117, 57, 130};
WiFiClient client;
const int httpPort = 80;
String url;
unsigned long timeout;

void sendData_2(){

    float suhu = value_temperature;
    float ph = value_ph;
    float amonia = value_mq_ppm;
    float tss = value_tss;
    float tds = raw_value_tds;
    float salinitas = averageVoltage;
    // Serial.println(suhu);
    // Serial.println(ph);
    // Serial.println(amonia);
    // Serial.println(tss);
    // Serial.println(tds);
    // Serial.println(salinitas);

    Serial.print("connecting to ");
    // Serial.println(server);

    if (!client.connect(server, httpPort))
    {
        Serial.println("connection failed");
        return;
    }

    // We now create a URI for the request
    url = "/api/monitoring/";
    url += id_alat;
    url += "/";

    url += nama;
    url += "/";
    
    url += ph;
    url += "/";
    
    url += suhu;
    url += "/";
    
    url += amonia;
    url += "/";
    
    url += tss;
    url += "/";
    
    url += tds;
    url += "/";
    
    url += salinitas;

    Serial.print("Requesting URL: ");
    Serial.println(url);

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: 103.117.57.130\r\n" +
                 "Connection: close\r\n\r\n");
    timeout = millis();
    while (client.available() == 0)
    {
        if (millis() - timeout > 5000)
        {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server and print them to Serial
    while (client.available())
    {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }

    Serial.println();
    Serial.println("closing connection");
    Serial.println();

}




// =============================================

// #include <HTTPClient.h>  //Board = Version 2.7.4
// #include <ArduinoJson.h> //Library = arduinoJson 6.15.1

// const char *nama_2 = "Aquarium 5";
// const char *id_alat_2 = "5";
// // 103.117.57.130
// byte server_2[] = {103, 117, 57, 130};
// WiFiClient client_2;
// const int httpPort_2 = 80;
// String url_2;
// unsigned long timeout_2;

// void sendData_2(){
//     // Yang lama
//     // float suhu = value_ph;
//     // float ph = value_temperature;
//     // float amonia = value_mq_ppm;
//     // float tss = value_tss;
//     // float tds = raw_value_tds;
//     // float salinitas = averageVoltage;
    
//     // Yang Baru
//     float suhu = value_temperature;
//     float ph = value_ph;
//     float amonia = value_mq_ppm;
//     float tss = value_tss;
//     float tds = raw_value_tds;
//     float salinitas = averageVoltage;

//     // Serial.println(suhu);
//     // Serial.println(ph);
//     // Serial.println(amonia);
//     // Serial.println(tss);
//     // Serial.println(tds);
//     // Serial.println(salinitas);

//     Serial.print("connecting to ");
//     // Serial.println(server_2);

//     if (!client_2.connect(server_2, httpPort_2))
//     {
//         Serial.println("connection failed");
//         return;
//     }

//     // We now create a URI for the request
//     url_2 = "/api/monitoring/";
//     url_2 += id_alat_2;
//     url_2 += "/";

//     url_2 += nama_2;
//     url_2 += "/";
    
//     url_2 += ph;
//     url_2 += "/";
    
//     url_2 += suhu;
//     url_2 += "/";
    
//     url_2 += amonia;
//     url_2 += "/";
    
//     url_2 += tss;
//     url_2 += "/";
    
//     url_2 += tds;
//     url_2 += "/";
    
//     url_2 += salinitas;

//     Serial.print("Requesting URL_2: ");
//     Serial.println(url_2);

//     // This will send the request to the server_2
//     client_2.print(String("GET ") + url_2 + " HTTP/1.1\r\n" +
//                  "Host: 103.117.57.130\r\n" +
//                  "Connection: close\r\n\r\n");
//     timeout_2 = millis();
//     while (client_2.available() == 0)
//     {
//         if (millis() - timeout_2 > 5000)
//         {
//             Serial.println(">>> Client_2 Timeout_2 !");
//             client_2.stop();
//             return;
//         }
//     }

//     // Read all the lines of the reply from server_2 and print them to Serial
//     while (client_2.available())
//     {
//         String line = client_2.readStringUntil('\r');
//         Serial.print(line);
//     }

//     Serial.println();
//     Serial.println("closing connection");
//     Serial.println();

// }
