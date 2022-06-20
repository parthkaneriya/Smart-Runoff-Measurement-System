
// Include NewPing Library for HC-SR04 sensor
#include <NewPing.h>
 
// Include Arduino Wire library for I2C
#include <Wire.h>
 
// Define Slave I2C Address
#define SLAVE_ADDR 9
 
// Hook up 13 HC-SR04 sensors in 1-pin mode
// tank 1
#define TRIGGER_PIN_1  2
#define ECHO_PIN_1     2
 
// tank 2
#define TRIGGER_PIN_2  3
#define ECHO_PIN_2     3
 
// tank 3
#define TRIGGER_PIN_3  4
#define ECHO_PIN_3     4
 
// tank 4
#define TRIGGER_PIN_4  5
#define ECHO_PIN_4     5

// tank 5
#define TRIGGER_PIN_5  6
#define ECHO_PIN_5     6

// tank 6
#define TRIGGER_PIN_6  7
#define ECHO_PIN_6     7

// tank 7
#define TRIGGER_PIN_7  8
#define ECHO_PIN_7     8

// tank 8
#define TRIGGER_PIN_8  9
#define ECHO_PIN_8     9

// tank 9
#define TRIGGER_PIN_9  10
#define ECHO_PIN_9     10

// tank 10
#define TRIGGER_PIN_10  11
#define ECHO_PIN_10     11

// tank 11
#define TRIGGER_PIN_11  12
#define ECHO_PIN_11     12

// tank 12
#define TRIGGER_PIN_12  13
#define ECHO_PIN_12     13

// tank 13
#define TRIGGER_PIN_13  14
#define ECHO_PIN_13     14
 
// Maximum Distance is 400 cm
#define MAX_DISTANCE 400
 
// Create objects for ultrasonic sensors
NewPing tank1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing tank2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing tank3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing tank4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);
NewPing tank5(TRIGGER_PIN_5, ECHO_PIN_5, MAX_DISTANCE);
NewPing tank6(TRIGGER_PIN_6, ECHO_PIN_6, MAX_DISTANCE);
NewPing tank7(TRIGGER_PIN_7, ECHO_PIN_7, MAX_DISTANCE);
NewPing tank8(TRIGGER_PIN_8, ECHO_PIN_8, MAX_DISTANCE);
NewPing tank9(TRIGGER_PIN_9, ECHO_PIN_9, MAX_DISTANCE);
NewPing tank10(TRIGGER_PIN_10, ECHO_PIN_10, MAX_DISTANCE);
NewPing tank11(TRIGGER_PIN_11, ECHO_PIN_11, MAX_DISTANCE);
NewPing tank12(TRIGGER_PIN_12, ECHO_PIN_12, MAX_DISTANCE);
NewPing tank13(TRIGGER_PIN_13, ECHO_PIN_13, MAX_DISTANCE);

 
// Define return data array, one element per sensor
int a[13];
int tankreading[13];
int iterations = 5;

// Define counter to count bytes in response
int bcount = 0;
 
void setup() {
 Serial.begin(9600);
  // Initialize I2C communications as Slave 
  Wire.begin(SLAVE_ADDR);
   // Function to run when data requested from master
  Wire.onRequest(requestEvent); 
  
}
 
void requestEvent() {
 
  // Define a byte to hold data
  byte myArray[2];
  int16_t bval;
  
  // Cycle through data
  // First response is always 255 to mark beginning
  switch (bcount) {
    case 0:
      bval = 255;
      break;
    case 1:
      bval = tankreading[0];
      break;
    case 2:
      bval = tankreading[1];
      break;
    case 3:
      bval = tankreading[2];
      break;
    case 4:
      bval = tankreading[3];
      break;
    case 5:
      bval = tankreading[4];
      break;
    case 6:
      bval = tankreading[5];
      break;
    case 7:
      bval = tankreading[6];
      break;
    case 8:
      bval = tankreading[7];
      break;
    case 9:
      bval = tankreading[8];
      break;
    case 10:
      bval = tankreading[9];
      break;
    case 11:
      bval = tankreading[10];
      break;
    case 12:
      bval = tankreading[11];
      break;
    case 13:
      bval = tankreading[12];
      break;
  }
  // Send response back to Master
  myArray[0] = (bval >> 8) & 0xFF;
  myArray[1] = bval & 0xFF;
  Wire.write(myArray, 2);
  
  
  // Increment byte counter
  bcount = bcount + 1;
  if (bcount > 13) bcount = 0;
 
}
 
void readDistance()
{
  //tank1
  a[0] = tank1.ping_median(iterations);
  a[0] = (a[0] / 2) * 0.343;
  tankreading[0]=732-a[0];
  if (a[0] > 742 ) {
    tankreading[0] = 0;
  }
  Serial.print("tankreading1 :");
  Serial.println(tankreading[0]);
  Serial.print("sensor1 :");
  Serial .println(a[0]);
  delay(20);
  
  //tank2
  a[1] = tank2.ping_median(iterations);
  a[1] = (a[1] / 2) * 0.343;
  tankreading[1]=720-a[1];
  if (a[1] > 800 ) {
    tankreading[1] = 0;
  }
  Serial.print("tankreading2 :");
  Serial.println(tankreading[1]);
  Serial.print("sensor2 :");
  Serial.println(a[1]);
  delay(20);

  //tank3
  a[2] = tank3.ping_median(iterations);
  a[2] = (a[2] / 2) * 0.343;
  tankreading[2]=720-a[2];
  if (a[2] > 800 ) {
    tankreading[2] = 0;
  }
  Serial.print("tankreading3 :");
  Serial.println(tankreading[2]);
  Serial.print("sensor3 :");
  Serial.println(a[2]);
  delay(20);

  //tank4
  a[3] = tank4.ping_median(iterations);
  a[3] = (a[3] / 2) * 0.343;
  tankreading[3]=720-a[3];
  if (a[3] > 800 ) {
    tankreading[3] = 0;
  }
  Serial.print("tankreading4 :");
  Serial.println(tankreading[3]);
  Serial.print("sensor4 :");
  Serial.println(a[3]);
  delay(20);

  //tank5
  a[4] = tank5.ping_median(iterations);
  a[4] = (a[4] / 2) * 0.343;
  tankreading[4]=720-a[4];
  if (a[4] > 800 ) {
    tankreading[4] = 0;
  }
  Serial.print("tankreading5 :");
  Serial.println(tankreading[4]);
  Serial.print("sensor5 :");
  Serial.println(a[4]);
  delay(20);

  //tank6
  a[5] = tank6.ping_median(iterations);
  a[5] = (a[5] / 2) * 0.343;
  tankreading[5]=720-a[5];
  if (a[5] > 800 ) {
    tankreading[5] = 0;
  }
  Serial.print("tankreading6 :");
  Serial.println(tankreading[5]);
  Serial.print("sensor6 :");
  Serial.println(a[5]);
  delay(20);

  //tank7
  a[6] = tank7.ping_median(iterations);
  a[6] = (a[6] / 2) * 0.343;
  tankreading[6]=737-a[6];
  if (a[6] > 747 ) {
    tankreading[6] = 0;
  }
  Serial.print("tankreading7 :");
  Serial.println(tankreading[6]);
  Serial.print("sensor7 :");
  Serial.println(a[6]);
  delay(20);

  //tank8
  a[7] = tank8.ping_median(iterations);
  a[7] = (a[7] / 2) * 0.343;
  tankreading[7]=762-a[7];
  if (a[7] > 772 ) {
    tankreading[7] = 0;
  }
  Serial.print("tankreading8 :");
  Serial.println(tankreading[7]);
  Serial.print("sensor8 :");
  Serial.println(a[7]);
  delay(20);

  //tank9
  a[8] = tank9.ping_median(iterations);
  a[8] = (a[8] / 2) * 0.343;
  tankreading[8]=735-a[8];
  if (a[8] > 745 ) {
    tankreading[8] = 0;
  }
  Serial.print("tank9 :");
  Serial.println(tankreading[8]);
  Serial.print("tank9 :");
  Serial.println(a[8]);
  delay(20);

  //tank10
  a[9] = tank10.ping_median(iterations);
  a[9] = (a[9] / 2) * 0.343;
  tankreading[9]=800-a[9];
  if (a[9] > 800 ) {
    tankreading[9] = 0;
  }
  Serial.print("tank10 :");
  Serial.println(tankreading[9]);
  Serial.print("tank10 :");
  Serial.println(a[9]);
  delay(20);

  //tank11
  a[10] = tank11.ping_median(iterations);
  a[10] = (a[10] / 2) * 0.343;
  tankreading[10]=800-a[10];
  if (a[10] > 800 ) {
    tankreading[10] = 0;
  }
  Serial.print("tank11 :");
  Serial.println(tankreading[10]);
  Serial.print("tank11 :");
  Serial.println(a[10]);
  delay(20);

  //tank12
  a[11] = tank12.ping_median(iterations);
  a[11] = (a[11] / 2) * 0.343;
  tankreading[11]=704-a[11];
  if (a[11] > 714 ) {
    tankreading[11] = 0;
  }
  Serial.print("tank12 :");
  Serial.println(tankreading[11]);
  Serial.print("tank12 :");
  Serial.println(a[11]);
  delay(20);

  //tank13
  a[12] = tank13.ping_median(iterations);
  a[12] = (a[12] / 2) * 0.343;
  tankreading[12]=708-a[12];
  if (a[12] > 718 ) {
    tankreading[12] = 0;
  }
  Serial.print("tank13 :");
  Serial.println(tankreading[12]);
  Serial.print("tank13 :");
  Serial.println(a[12]);
  delay(20);
}
 
void loop()
{
  // Refresh readings every ten minute
  readDistance();
  Serial.println("wait for 10 min"); 
  Serial.println(""); 
  delay(600000);
}

