//garage parking help on chip
//uses hc-sr04 ultrasonic sensor and led
//runs on atmega328 chip

//minimal distance in CM when to turn on the green led.
#define min_distance 150
//pin which the green LED is connected to
#define green_led_pin 7
//pin which the red LED is connected to
#define red_led_pin 8

//ultrasonic sensor
#define trigger_pin 12
#define echo_pin 13
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


void setup() {
  pinMode(green_led_pin, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
}

void loop() {
   // Clears the trigPin condition
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance>=min_distance) {
    digitalWrite(green_led_pin,HIGH);
    digitalWrite(red_led_pin,LOW);
  }
  else {
    digitalWrite(green_led_pin,LOW);
    digitalWrite(red_led_pin,HIGH);
  }
}

