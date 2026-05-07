// 基礎プログラミングII 第3回 Scrummyプロジェクト
#include <SchooMyUtilities.h>
SchooMyUtilities scmUtils = SchooMyUtilities();


float time = 0;
unsigned long distanceTimeOut = 100000;
float _sbeGetDistanceUsingDistanceSensor(int trigPin, int echoPin) {
 long distance = 0;
 long duration = 0;


 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);


 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH, distanceTimeOut);
 if (duration > 0) {
   distance = duration / 2 * 340 * 100 / 1000000;
 }
 return distance;
}


void setup() {
 Serial.begin(9600);
 digitalWrite(18, LOW);
vm..jjj time = 0;
}


void loop() {
 if ((_sbeGetDistanceUsingDistanceSensor(18 , 19) == 10) && (time == 3)) {
   time = 0;
 }
 delay(1000);
}
