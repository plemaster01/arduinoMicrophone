const int quietPin = 2;
const int loudPin = 4;
const int greenPin = 12;
const int redPin = 13;
int quietState = 0;
int loudState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(quietPin, INPUT);
  pinMode(loudPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  quietState = digitalRead(quietPin);
  loudState = digitalRead(loudPin);
  if (quietState == 0 and loudState == 0) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    delay(100);
    Serial.println("loud");
  }
  else if (quietState == 0 and loudState == 1) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    delay(10);
    Serial.println("quiet");
  }
  else if (quietState == 1 and loudState == 0) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    delay(100);
    Serial.println("wait what");
  }
  else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(10);
    Serial.println("silent");
  }
}
