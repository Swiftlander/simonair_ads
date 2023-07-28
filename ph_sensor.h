
// ==========
// SENSOR PH
// ==========

float raw_adc_ph, voltage_ph, value_ph;

// Akuarium 1 = (voltage_ph - 3.2178) / -0.1667;
// Akuarium 2 = (voltage_ph - 3.6782) / -0.1519;
// Akuarium 3 = (voltage_ph - 3.672) / -0.1605;
// Akuarium 4 = (voltage_ph - 3.1534) / -0.1035;
// Akuarium 5 = (voltage_ph - 3.7904) / -0.1769;
// Akuarium 6 = (voltage_ph - 3.7956) / -0.1746;

// Regresi Linear
// Akuarium 1 = -0.0753*x + 8.52

void phSensor(){
    raw_adc_ph = read_by_ads_ph();
    voltage_ph = ads.computeVolts(raw_adc_ph);
    value_ph = (voltage_ph - 3.7956) / -0.1746;
    // value_ph = -0.0753 * value_ph + 8.52;
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
