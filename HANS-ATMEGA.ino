#define tdsPin A0
#define pressurePin A1
#define turbidityPin A2
#define flowPin 2
#define valvePin 4



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tdsPin, INPUT);
  pinMode(pressurePin, INPUT);
  pinMode(2, INPUT);
  // attachInterrupt(digitalPinToInterrupt(2), increase, RISING);
}
float volume; 
volatile long pulse;
unsigned long lastTime;

void loop() {
  // TDS sensor code:
  int analogValuetds = analogRead(tdsPin);
  float voltagetds = analogValuetds * (5.0 / 1023.0);
  float tdsValue = (voltagetds * 1000) * 0.5;
  // END of TDS sensor code with a final value stored in tdsValue variable
  
  //Pressure sensor code:
  float voltagepr = analogRead(pressurePin) * (5.0 / 1023.0);
  float pressure = max(((voltagepr - 0.5) * 0.5 / 4.5) * 145, 0) ; // pressure = voltage - min voltage * max pressure / voltage difference 
  // END of Pressure sensor code and the final pressure value stored in pressure variable in PSI

  //Turbidity sensor code:
  float turbidity = analogRead(turbidityPin) * (5.0 / 1023.0);
  // Here we should determine the max and min NTU for our system to continue, 0-3.6 volts range

  // Flow sensor code:
  Serial.println(digitalRead(2));

  delay(1000);
  
}

void increase() {
  pulse++;
}
