/*Author: Priyatham Rao Valipe
 *Email : priyathamvalipe10@gmail.com
 *GitHub: https://github.com/priyathamrao
 *
 *This is the code for capacitive touch sensor based indicator using
 *Arduino Nano.It has 4 indication levels represented by 4 LED's. 
 *For first touch the LED will be blinking and for the second touch LED 
 *will be steady, like this this code will give 8 indications with 4 LED's. 
 * 
 * ~~~D7 is the INPUT signal from sensor~~~
 * ~~~ Connect 5V and GND from Arduino Nano toSensor~~~
 * ~~~D2,D3,D4,D5 are the LED's OUTPUT pins~~~ 
 */



int i = 0;// initialize the count as 0
void D_2(){
  digitalWrite( 2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}
void D_3(){
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  delay(500);
}
void D_4(){
  digitalWrite(4 , HIGH);
  delay(500);
  digitalWrite(4 , LOW);
  delay(500); 
}
void D_5(){
  digitalWrite( 5, HIGH);
  delay(500);
  digitalWrite( 5, LOW);
  delay(500);
}

#define sensorPin 7 // capactitive touch sensor - Arduino Nano Digital pin D7
 
int ledPin = 2; // Output display LED (on board LED) - Arduino Nano Digital pin D2
 
void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
  Serial.print("CAPACITIVE TOUCH SENSOR BASED INDICATION");
}
 
void loop() {
  int senseValue = digitalRead(sensorPin);
  if (senseValue == HIGH)
  {
    i++;//increment the count if sensor output is high
    Serial.println("TOUCHED");
  }
  else{
    i;
    Serial.println("not touched");
  } 
  delay(500);
  switch(i)
{
  case 1:
  D_2();
  Serial.println("Level 1 Half");
  break;
  
  case 2:
  Serial.println("Level 1 Full");
  digitalWrite(2, HIGH);
  delay(100);
  break;
  
  case 3:
  D_3();
  Serial.println("Level 2 Half");
  break;
  
  case 4:
  Serial.println("Level 2 Full");
  digitalWrite(3 , HIGH);
  break;
  
  case 5:
  Serial.println("Level 3 Half");
  D_4();
  break;
  
  case 6:
  Serial.println("Level 3 Full");
  digitalWrite( 4, HIGH);
  delay(100);
  break;
  
  case 7:
  Serial.println("Level 4 Half");
  D_5();
  break;

  case 8:
  Serial.println("Level 4 Full");
  digitalWrite(5, HIGH);
  delay(100);
  break;
  
  default:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);  
} 
}


