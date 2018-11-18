// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
char state = 0;
boolean replay =true;

// defines variables
long duration;
int distance;
int safetyDistance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

                                                                            
void loop() {
// Clears the trigPin
if(Serial.available() > 0){
  state = Serial.read();
}
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 40){
  state='1';
  digitalWrite(buzzer, HIGH);
  Serial.println("SOMEONE IS THERE");
  Serial.print("Distance: ");
Serial.println(distance);
delay(1000);
digitalWrite(buzzer,LOW);
} 
else{
  digitalWrite(buzzer, LOW);
}

// Prints the distance on the Serial Monitor

}
