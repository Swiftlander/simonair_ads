
// ==========
// MQ-137
// ==========

// #define RL 4.7  //The value of resistor RL is 47K

// #define m -0.263 //Enter calculated Slope 
// #define b 0.42 //Enter calculated intercept
// #define Ro_final 20 //Enter found Ro value

const float RL  = 4.7;  //The value of resistor RL is 47K

const float m = -0.263; //Enter calculated Slope 
const float b = 0.42; //Enter calculated intercept
const float Ro_final = 20; //Enter found Ro value


float analog_value_searchRO;
float VRL_searchRO;
float Rs_searchRO;
float Ro_searchRO;

float VRL; //Voltage drop across the MQ sensor
float Rs; //Sensor resistance at gas concentration 
float ratio; //Define variable for ratio
float value_mq_ppm = 0;


void searchROMQ(){

  for(int test_cycle = 1 ; test_cycle <= 500 ; test_cycle++) //Read the analog output of the sensor for 200 times
  {
    analog_value_searchRO = analog_value_searchRO + read_by_ads_mq(); //add the values for 200
  }
  analog_value_searchRO = analog_value_searchRO/500.0; //Take average
  VRL_searchRO = ads.computeVolts(analog_value_searchRO); //Convert analog value to voltage
  //RS = ((Vc/VRL)-1)*RL is the formulae we obtained from datasheet
  Rs_searchRO = ((5.0/VRL)-1) * RL;
  //RS/RO is 3.6 as we obtained from graph of datasheet
  Ro_searchRO = Rs/3.6;
  delay(1000); //delay of 1sec

}

void mqSensor() {

  read_by_ads_mq();

  VRL = ads.computeVolts(adc3_mq); //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
  ratio = Rs/Ro_final;  // find ratio Rs/Ro

  // value_mq_ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm
  value_mq_ppm = VRL; //use formula to calculate ppm
}

void mqPrintToSerialMonitor(){
  Serial.println("============== MQ ==============");
  Serial.print("ADC MQ: ");
  Serial.println(adc3_mq);
  Serial.print("ADC Voltage MQ: ");
  Serial.println(ads.computeVolts(adc3_mq));
  Serial.print("RO MQ: ");
  Serial.println(Ro_searchRO);
  Serial.print("Nilai MQ Ammonia: ");
  Serial.println(value_mq_ppm);

}
