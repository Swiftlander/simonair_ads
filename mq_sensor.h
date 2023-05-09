
// ==========
// MQ-137
// ==========
// #define RL 10    // nilai RL = 10 pada sensor
// #define m -0.417 // hasil perhitungan gradien
// #define b 0.425  // hasil perhitungan perpotongan
// #define Ro 205   // hasil pengukuran RO

const int RL = 10;
const float m = -0.417;
const float b = 0.425;
const int Ro = 205;

int raw_mq_analogValue = 0;

int fixADCAmmonia;
int avgADCAmmonia[10];
int tempADCAmmonia;
float ammoniaVoltage;
double ADCAmmonia;

float VRL, RS, ratio;

float readings[SAMPLE_VALUE];
int readIndex = 0;
float total = 0;
float average = 0;
float value_mq_ppm = 0;

void mqSensor(){

    fixADCAmmonia = 0;
    tempADCAmmonia = 0;
    ADCAmmonia = 0;

    for (int i = 0; i < SAMPLE_VALUE; i++)
    {
        ADCAmmonia = read_by_ads_mq();
        avgADCAmmonia[i] = ADCAmmonia;
    }

    for (int i = 0; i < SAMPLE_VALUE; i++)
    {
        tempADCAmmonia += avgADCAmmonia[i];
    }

    fixADCAmmonia = tempADCAmmonia / SAMPLE_VALUE;

    ammoniaVoltage = fixADCAmmonia * (3.3f / 4095.0f); // konversi analog ke tegangan
    RS = (3.3 / ammoniaVoltage - 1) * 10;              // rumus untuk RS
    ratio = RS / Ro;                                   // rumus mencari ratio
    value_mq_ppm = pow(10, ((log10(ratio) - b) / m));           // rumus mencari ppm

}

void mqPrintToSerialMonitor(){
  Serial.println("============== MQ ==============");
  Serial.print("ADC MQ: ");
  Serial.println(adc3_mq);
  Serial.print("ADC Voltage MQ: ");
  Serial.println(ads.computeVolts(adc3_mq));
  Serial.print("Nilai MQ: ");
  Serial.println(value_mq_ppm);

}
