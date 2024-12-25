const int PIR_SENSOR_OUTPUT_PIN = 2;  /* PIR sensor O/P pin */
const int buzzer = 9; //buzzer to arduino pin 9
int state;

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  attachInterrupt(digitalPinToInterrupt(2), pir, HIGH);  /* Interrupt on rising edge on pin 2 */
  Serial.begin(9600); /* Define baud rate for serial communication */
  
}

void loop() {
  delay(10000); /* Power On Warm Up Delay */
  digitalWrite(LED_BUILTIN, LOW);
  noTone(buzzer);
}

void pir(){
  state = digitalRead(PIR_SENSOR_OUTPUT_PIN);
  Serial.println("Object Detected");
  digitalWrite(LED_BUILTIN, HIGH);
  tone(buzzer, 1000);
  delay(300000);	//LED will be on for five minutes
}