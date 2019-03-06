#define ENABLE 5
#define FORWARD 3
#define BACKWARD 4
int dir = 0; //temporary variable until we get the app running

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // when we receive an input from the person (via a mobile app)
  dir = digitalRead(2); //for the prototype we will take the input from 2 buttons
  //if direction is 1 it is forward, 2 back, and the rest we will do later once we have built the car :)
  if (dir == LOW) {
    //forward. for the prototype we will use button not pressed as forwards and pressed as backwards
    Serial.println("LOW: Forward");
    digitalWrite(ENABLE,LOW);
    digitalWrite(ENABLE,HIGH); //will change to PWM once we get a 6V battery
    digitalWrite(FORWARD,HIGH); //we will do this so that it gradually increases its speed
    digitalWrite(BACKWARD,LOW);
    delay(250);
  }
  else {//backwards
    Serial.println("HIGH: Backwards");
    digitalWrite(ENABLE,LOW);
    digitalWrite(ENABLE,HIGH);
    digitalWrite(FORWARD,LOW);
    digitalWrite(BACKWARD,HIGH);
    delay(250);
  }

}
