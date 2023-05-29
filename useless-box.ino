#include <Servo.h>
Servo servoMana;
Servo servoCapac;

int action = 1;
const int switchPin = A2;
const int servoManaPin = 5;
const int servoCapacPin = 6;
const int ledPin = 12;

const int pozitieManaRetrasa = 180;
const int pozitieManaIesita = 5;
const int pozitieCapacInchis = 20;
const int pozitieCapacDeschis = 95;

void setup(){
	Serial.begin(9600);
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);
	servoMana.attach(servoManaPin);
	servoCapac.attach(servoCapacPin);
	servoMana.write(pozitieManaRetrasa);
	servoCapac.write(pozitieCapacInchis);
	stopServoCapac();
}

void loop(){
	if (digitalRead(switchPin) == LOW) {
		digitalWrite(ledPin, HIGH);
		action = random(1, 3);
		if (action == 1){
			Serial.println("Action 1");
			delay(1000);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacDeschis);
			delay(500);
//			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++){
//				servoCapac.write(i);
//				delay(5);
//			}
			stopServoCapac();
//			for (int i = pozitieManaRetrasa; i >= pozitieManaIesita; i--){
//				servoMana.write(i);
//				delay(10);
//			}
			servoMana.write(pozitieManaIesita);
			delay(500);
			digitalWrite(ledPin, LOW);
			servoMana.write(pozitieManaRetrasa);
			delay(1000);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacInchis);
//			for (int i = pozitieCapacDeschis; i >= pozitieCapacInchis; i--){
//				servoCapac.write(i);
//				delay(10);
//			}
			stopServoCapac();			
		}else if (action == 2){
			Serial.println("Action 2");
			delay(1000);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacDeschis);
			stopServoCapac();
			for (int i = pozitieManaRetrasa; i >= pozitieManaIesita; i--){
				servoMana.write(i);
				delay(15);
			}
			digitalWrite(ledPin, LOW);
			delay(1000);
			servoMana.write(pozitieManaIesita + 40);
			delay(3000);
			servoMana.write(pozitieManaIesita);
			delay(2000);
			servoMana.write(pozitieManaRetrasa);
			delay(500);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacInchis);
			stopServoCapac();
		}else if (action == 3){
			Serial.println("Action 3");
			delay(1000);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacDeschis);
			stopServoCapac();
			delay(2000);
			servoCapac.attach(servoCapacPin);
			for (int i = pozitieCapacDeschis; i >= pozitieCapacInchis; i--)	{
				servoCapac.write(i);
				delay(10);
			}
			stopServoCapac();
			delay(1000);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacDeschis);
			stopServoCapac();
			servoMana.write(pozitieManaIesita);
			delay(500);
			digitalWrite(ledPin, LOW);
			servoMana.write(pozitieManaRetrasa);
			delay(300);
			servoCapac.attach(servoCapacPin);
			servoCapac.write(pozitieCapacInchis);
			stopServoCapac();
		}else if (action == 4){
			Serial.println("Action 4");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++)	{
				servoCapac.write(i);
				delay(20);
			}
			for (int i = pozitieManaIesita; i >= pozitieManaRetrasa; i--){
				servoMana.write(i);
				delay(20);
			}
			delay(2000);
			servoMana.write(pozitieManaRetrasa);
			delay(200);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 5){
			Serial.println("Action 5");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(2000);
			servoMana.write(65);
			delay(550);
			servoMana.write(40);
			delay(200);
			servoMana.write(65);
			delay(200);
			servoMana.write(40);
			delay(200);
			servoMana.write(65);
			delay(200);
			servoMana.write(40);
			delay(200);
			servoMana.write(65);
			delay(200);
			servoMana.write(40);
			delay(200);
			servoMana.write(65);
			delay(200);
			servoMana.write(40);
			delay(200);
			servoMana.write(65);
			delay(2000);
			servoMana.write(pozitieManaRetrasa);
			delay(400);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 6){
			Serial.println("Action 6");
			for (int i = 70; i < 110; i++){
				servoCapac.write(i);
				delay(20);
			}
			delay(1000);
			for (int i = 0; i < 12; i++){
				for (int j = 70; j <= 110; j++) {
					servoCapac.write(j);
					delay(6);
				}
				delay(200);
			}
			for (int i = 180; i >= 35; i--){
				servoMana.write(i);
				delay(30);
			}
			servoMana.write(pozitieManaRetrasa);
			delay(400);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			delay(1500);
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(3000);
			servoCapac.write(80);
			action++;
		}else if (action == 7){
			Serial.println("Action 7");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(400);
			servoMana.write(pozitieManaRetrasa);
			delay(1000);
			for (int i = 0; i < 6; i++){
				for (int j = 70; j <= 110; j++) {
					servoCapac.write(j);
					delay(6);
				}
				delay(200);
			}
			delay(500);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 8){
			Serial.println("Action 8");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++) {
				servoCapac.write(i);
				delay(6);
			}
			servoMana.write(pozitieManaRetrasa);
			delay(2000);
			for (int i = 0; i < 7; i++){
				servoMana.write(75);
				delay(100);
				servoMana.write(40);
				delay(100);
			}
			delay(500);
			servoMana.write(pozitieManaIesita);
			delay(1000);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 9){
			Serial.println("Action 9");
			for (int i = 70; i <= 105; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(2000);
			servoCapac.write(110);
			for (int i = 180; i >= 35; i--){
				servoMana.write(i);
				delay(40);
			}
			delay(500);
			servoMana.write(pozitieManaRetrasa);
			delay(200);
			for (int i = 26; i <= 180; i++){
				servoMana.write(i);
				delay(40);
			}
			servoCapac.write(pozitieCapacInchis);
			delay(2000);
			servoCapac.write(100);
			delay(3000);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 10){
			Serial.println("Action 10");
			for (int i = 70; i <= 105; i++){
				servoCapac.write(i);
				delay(100);
			}
			delay(1000);
			for (int i = 0; i < 10; i++){
				for (int j = 70; j <= 100; j++) {
					servoCapac.write(j);
					delay(6);
				}
				delay(100);
			}
			servoCapac.write(110);
			delay(100);
			servoMana.write(pozitieManaRetrasa);
			delay(650);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 11){
			Serial.println("Action 11");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++){
				servoCapac.write(i);
				delay(6);
			}
			servoMana.write(pozitieManaRetrasa);
			delay(2000);
			for (int i = 0; i < 3; i++){
				servoMana.write(65);
				delay(200);
				servoMana.write(40);
				delay(200);
			}
			delay(1500);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			delay(1500);
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++) {
				servoCapac.write(i);
				delay(6);
			}
			servoMana.write(pozitieManaRetrasa);
			delay(3000);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 12){
			Serial.println("Action 12");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++){
				servoCapac.write(i);
				delay(50);
			}
			delay(1000);
			for (int i = 180; i >= 26; i--){
				servoMana.write(i);
				delay(50);
			}
			delay(2000);
			servoMana.write(pozitieManaRetrasa);
			delay(200);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 13){
			Serial.println("Action 13");
			for (int i = pozitieCapacInchis; i <= pozitieCapacDeschis; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(2000);
			for (int i = 180; i >= 60; i--){
				servoMana.write(i);
				delay(40);
			}
			for (int i = 0; i < 3; i++){
				servoMana.write(60);
				delay(200);
				servoMana.write(40);
				delay(800);
			}
			servoMana.write(pozitieManaRetrasa);
			delay(2000);
			servoMana.write(pozitieManaIesita);
			delay(500);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 14){
			Serial.println("Action 14");
			for (int i = 70; i <= 105; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(4000);
			servoCapac.write(110);
			servoMana.write(pozitieManaRetrasa);
			delay(650);
			servoMana.write(pozitieManaIesita);
			delay(500);
			servoCapac.write(100);
			delay(4000);
			servoCapac.write(pozitieCapacInchis);
			action++;
		}else if (action == 15){
			Serial.println("Action 15");
			for (int i = 70; i <= 105; i++) {
				servoCapac.write(i);
				delay(6);
			}
			delay(1000);
			for (int i = 0; i < 3; i++){
				for (int j = 70; j <= 105; j++){
					servoCapac.write(j);
					delay(50);
				}
				for (int j = 105; j >= 70; j--){
					servoCapac.write(j);
					delay(50);
				}
			}
			for (int j = 70; j <= 110; j++){
				servoCapac.write(j);
				delay(50);
			}
			for (int i = 180; i >= 35; i--){
				servoMana.write(i);
				delay(40);
			}
			delay(1000);
			servoMana.write(pozitieManaRetrasa);
			delay(400);
			servoMana.write(pozitieManaIesita);
			delay(400);
			servoCapac.write(pozitieCapacInchis);
			action = 1;
		}
	}
}

void stopServoCapac(){
	delay(600);
	servoCapac.detach();
	pinMode(servoCapacPin, OUTPUT);
	digitalWrite(servoCapacPin, LOW);
}
