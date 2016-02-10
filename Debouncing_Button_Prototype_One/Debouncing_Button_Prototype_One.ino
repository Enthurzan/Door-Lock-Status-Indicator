//I/O Variables 
int button = 8;
int led = 9;

//Debouncing Variables
unsigned long start = millis();
unsigned long readBegin;
unsigned long readLength;
bool previousState = LOW; // previous state of the button
bool currentState; // as of now, button is LOW, but this will change later

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  readBegin = millis();
  currentState = digitalRead(button);
  if (previousState == LOW && currentState == HIGH) //prevents boucing because it will read the previousState as HIGH and not turn LED on
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }
  previousState = currentState; //updates the previousState after running the Output if statement
  readLength = start - readBegin;

}
