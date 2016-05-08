//I/O Variables
int button = 9;
int led = 7 ;

//Debouncing Variables
unsigned long start = millis();
unsigned long readBegin;
unsigned long readEnd;
unsigned long readLength = 0;
bool previousState = LOW; // previous state of the button
bool currentState; // as of now, button is LOW, but this will change later

void setup() {
  Serial.begin(9600); //9600 baud Serial monitor (for troubleshooting)

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);//makes sure the LED starts at the LOW settings

}

void loop() {

  currentState = digitalRead(button); //reads the current state of the button
  readBegin = millis(); //starts the readBegin millis here to find the time that the program begins the I/O code
  if (previousState == LOW && currentState == LOW) {
    digitalWrite(led, LOW);
    delay(500);
    currentState = digitalRead(button);
  }
  else if (previousState == LOW && currentState == HIGH) //prevents boucing because it will read the previousState as HIGH and not turn LED on
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    currentState = digitalRead(button);

  }
  else {
    delay(500);
    currentState = digitalRead(button);
  }
}
