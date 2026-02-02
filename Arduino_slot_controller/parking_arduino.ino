#define TRIG1 2
#define ECHO1 3
#define TRIG2 4
#define ECHO2 5

long duration;
int distance;
int slot1, slot2;

void setup() {
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  Serial.begin(9600);      // USB Monitor
  Serial1.begin(9600);     // UART to ESP32 (use Mega / Nano Every)
}

int readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  int d1 = readDistance(TRIG1, ECHO1);
  int d2 = readDistance(TRIG2, ECHO2);

  slot1 = (d1 < 10) ? 1 : 0;   // 1 = occupied
  slot2 = (d2 < 10) ? 1 : 0;

  // Send data as CSV
  Serial1.print(slot1);
  Serial1.print(",");
  Serial1.println(slot2);

  // Debug
  Serial.print("Slot1: ");
  Serial.print(slot1);
  Serial.print(" Slot2: ");
  Serial.println(slot2);

  delay(1000);
}
