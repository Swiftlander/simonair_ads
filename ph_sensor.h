
// ==========
// SENSOR PH
// ==========

float raw_adc_ph, voltage_ph, value_ph;

// kalibrasi Ph
// float PH4 = 2.96f;
// float PH7 = 2.6f;

// Akuarium 1 = (voltage_ph - 3,2178) / -0,1167;
// Akuarium 2 = (voltage_ph - 3.8276) / -0.1599;
// Akuarium 4 = (voltage_ph - 3,8378) / -0,1744;
// Akuarium 5 = (voltage_ph - 3.7572) / -0.1708;
// Akuarium 6 = (voltage_ph + 0.491) / 0.4491;

// y = -0,1684x + 4,8554



void phSensor(){
    raw_adc_ph = read_by_ads_ph();
    voltage_ph = ads.computeVolts(raw_adc_ph);
    value_ph = (voltage_ph - 4,8554) / -0,1684;
}

void phPrintToSerialMonitor(){
  Serial.println("============== PH ==============");
  Serial.print("ADC PH: ");
  Serial.println(raw_adc_ph);
  Serial.print("Voltage PH: ");
  Serial.println(voltage_ph);
  Serial.print("Nilai PH: ");
  Serial.println(value_ph);
  Serial.println();

}
