
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

int16_t adc0_ph, adc1_tds, adc2_tss, adc3_mq;
float volts_ph, volts_tds, volts_tss, volts_mq;

void setup_ads(){
  Wire.begin();

  if (!ads.begin()){
    Serial.println("Failed to initialize ADS.");
  }
}


int16_t read_by_ads_ph(){
  adc0_ph = ads.readADC_SingleEnded(0);  // Untuk Sensor PH
  return adc0_ph;
}

int16_t read_by_ads_tds(){
  adc1_tds = ads.readADC_SingleEnded(1);  // Untuk Sensor TDS
  return adc1_tds;
}

int16_t read_by_ads_tss(){
  adc2_tss = ads.readADC_SingleEnded(2);  // Untuk Sensor TSS/Turbidity
  return adc2_tss;
}

int16_t read_by_ads_mq(){
  adc3_mq = ads.readADC_SingleEnded(3);  // Untuk Sensor MQ
  return adc3_mq;
}


// void read_by_ads(){
//   volts_ph = ads.computeVolts(adc0_ph);
//   volts_tds = ads.computeVolts(adc1_tds);
  
 
//   volts_tss = ads.computeVolts(adc2_tss);
//   volts_mq = ads.computeVolts(adc3_mq);
// }