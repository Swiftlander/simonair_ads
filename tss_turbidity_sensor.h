
// ==========
// TSS/TURBIDITY
// ==========
float raw_adc_tss;
float voltage_tss;
float value_tss = 0;

// Akuarium 1 = (-28.5 * voltage_tss) + 128;
// Akuarium 3 = (4 * voltage_tss) + -6.1;
// Akuarium 5 = (-1.67 * voltage_tss) + 6.4;
// Akuarium 6 = (0.952 * voltage_tss) + 0.437;

void tssTurbiditySensor(){
  raw_adc_tss = read_by_ads_tss();
  voltage_tss = ads.computeVolts(raw_adc_tss);   
  value_tss = voltage_tss;   
}


void tssPrintToSerialMonitor(){
  Serial.println("============== TSS ==============");
  Serial.print("ADC TSS: ");
  Serial.println(raw_adc_tss);
  Serial.print("Voltage TSS: ");
  Serial.println(voltage_tss);
  Serial.print("Value TSS: ");
  Serial.println(value_tss);
  Serial.println();
}
