const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  while(Serial.available()) {
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();
    if(Serial.read() == '\n') {
      RGB(red, green, blue);
    }
  }
}

void RGB(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}
