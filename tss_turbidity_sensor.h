
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
  value_tss = voltage_tss; // comment baris ini jika rumus sudah ada;

  // if(nomor_akuarium == 1){
  //   value_tss = (-28.5 * voltage_tss) + 128;
  // }

  // if(nomor_akuarium == 2){
  //   value_tss = (-28.5 * voltage_tss) + 128;
  // }

  // if(nomor_akuarium == 3){
  //   value_tss = (4 * voltage_tss) + -6.1;
  // }

  // if(nomor_akuarium == 4){
  //   value_tss = (4 * voltage_tss) + -6.1;
  // }

  // if(nomor_akuarium == 5){
  //   value_tss = (-1.67 * voltage_tss) + 6.4;
  // }

  if(nomor_akuarium == 6){
    value_tss = (0.952 * voltage_tss) + 0.437;
  }

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
