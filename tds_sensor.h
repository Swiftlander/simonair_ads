// ==========
// SENSOR TDS
// ==========

// Default = 0.60

// Akuarium 1 = 0.47
// Akuarium 3 = 0.65
// Akuarium 4 = 0.63
// Akuarium 6 = 

// Hasil regresi linear
// Akuarium 1 = (0.438 * value_tds) + 2.87;
// Akuarium 2 = (0.79 * value_tds) + -34.5;
// Akuarium 3 = (0.542 * value_tds) + -16.1;
// Akuarium 4 = (0.453 * value_tds) + 1.9;
// Akuarium 5 = (0.572 * value_tds) + -30.8;
// Akuarium 6 = (0.444 * value_tds) + -7.04;

float raw_adc_tds, voltage_tds = 0, value_tds = 0;
int value_temperature_dummy = 25;

void tdsSensor()
{
  raw_adc_tds = read_by_ads_tds();
  voltage_tds = ads.computeVolts(raw_adc_tds);
  float compensationCoefficient = 1.0 + 0.02 * (value_temperature - 25.0);
  float compensationVoltage = voltage_tds / compensationCoefficient;
  value_tds = (133.42 * compensationVoltage * compensationVoltage * compensationVoltage - 255.86 * compensationVoltage * compensationVoltage + 857.39 * compensationVoltage) * 1;
  
  if(nomor_akuarium == 1){
    value_tds = (0.372 * value_tds) + 48.8;
  }
  
  if(nomor_akuarium == 2){
    value_tds = (0.712 * value_tds) + -9.26;
  }

  if(nomor_akuarium == 3){
    value_tds = (0.356 * value_tds) + 62;
  }

  if(nomor_akuarium == 4){
    value_tds = (0.389 * value_tds) + 45.1;
  }

  if(nomor_akuarium == 5){
    value_tds = (0.522 * value_tds) + 8.3;
  }

  if(nomor_akuarium == 6){
    value_tds = (0.445 * value_tds) + -7.49;
  }

  // if(nomor_akuarium == 2){
  //   value_tds = (0.79 * value_tds) + -34.5;
  // }

  // if(nomor_akuarium == 3){
  //   value_tds = (0.542 * value_tds) + -16.1;
  // }

  // if(nomor_akuarium == 4){
  //   value_tds = (0.453 * value_tds) + 1.9;
  // }
  
  // if(nomor_akuarium == 5){
  //   value_tds = (0.572 * value_tds) + -30.8;
  // }

  // if(nomor_akuarium == 6){
  //   value_tds = (0.444 * value_tds) + -7.04;
  // }
  
}

void tdsPrintToSerialMonitor(){
  Serial.println("============== TDS ==============");
  Serial.print("ADC TDS: ");
  Serial.println(raw_adc_tds);
  Serial.print("Voltage TDS: ");
  Serial.println(voltage_tds);
  Serial.print("TDS Value: ");
  Serial.print(value_tds);
  Serial.println("ppm");
  Serial.println();
}
