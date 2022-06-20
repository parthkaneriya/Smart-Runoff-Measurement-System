int sensorval;
float voltage,pressure;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorval=analogRead(A0);
delay(2000);
Serial.print("Sensor value:");
Serial.println(sensorval);
//voltage=(float(sensorval)*4.5)/1024;
delay(2000);
Serial.print("Voltage value:");
Serial.println(voltage);
}
