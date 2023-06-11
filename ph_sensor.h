
// ==========
// SENSOR PH
// ==========

int raw_ph_analogValue = 0;

float calibrationValue_ph = 26.34;

double raw_adc_ph;
double store_adc_value_ph[SAMPLE_VALUE];
double sum_all_array_value_ph = 0;
double adc_ph;
double voltage_ph;
double PH_step;
double value_ph;

// kalibrasi Ph
// float PH4 = 2.96f;
// float PH7 = 2.6f;

void phSensor(){
    raw_adc_ph = read_by_ads_ph();
    // voltage_ph = raw_adc_ph * (3.3 / 4095.0);
    voltage_ph = ads.computeVolts(adc0_ph);

    // value_ph = -5.70 * voltage_ph + calibrationValue_ph;
    // PH_step = (PH4 - PH7) / 3;
    // value_ph = (7.00f + ((PH7 - voltage_ph) / PH_step)) + 0.9f;
    // value_ph = -0.1763x + 3.677;
    value_ph = (voltage_ph - 3.636) / -0.1511;
}

void phPrintToSerialMonitor(){
  Serial.println("============== PH ==============");
  Serial.print("ADC PH: ");
  Serial.println(adc0_ph);
  Serial.print("Voltage PH: ");
  Serial.println(ads.computeVolts(adc0_ph));
  Serial.print("Nilai PH: ");
  Serial.println(value_ph);
}
