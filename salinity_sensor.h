// ==========
// SALINITAS
// ==========

double adc_salinity;
double voltage_salinity;
double value_salinity = 0;


void salinitySensor(){
  adc_salinity = read_by_ads_tds();
  voltage_salinity = ads.computeVolts(adc_salinity);
  value_salinity = voltage_salinity;
}

void salinityPrintToSerialMonitor(){
  Serial.println("============== SALINITY ==============");
  Serial.print("ADC salinity: ");
  Serial.println(adc_salinity);
  Serial.print("Voltage salinity: ");
  Serial.println(voltage_salinity);
  Serial.print("Salinity Value: ");
  Serial.println(value_salinity);
        
}