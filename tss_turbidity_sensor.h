
// ==========
// TSS/TURBIDITY
// ==========
int raw_tssTurbidity_analogValue = 0;
double raw_adc_tss;
double store_adc_value_tss[SAMPLE_VALUE];
double sum_all_array_value_tss = 0;
double adc_tss;
double voltage_tss;
double value_tss = 0;


void tssTurbiditySensor(){
  raw_adc_tss = read_by_ads_tss();
  value_tss =  ads.computeVolts(adc2_tss);   
}


void tssPrintToSerialMonitor(){
  Serial.println("============== TSS ==============");
  Serial.print("ADC TSS: ");
  Serial.println(adc2_tss);
  Serial.print("Voltage TSS: ");
  Serial.println(ads.computeVolts(adc2_tss));
  Serial.print("Value TSS: ");
  Serial.println(value_tss);
  Serial.println();
}
