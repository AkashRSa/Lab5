SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

// setup() runs once, when the device is first turned on.
void setup()
{

  // Put initialization like pinMode and begin functions here.
  pinMode(D5, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{ 
  uint16_t sMi = analogRead(A5);
  uint16_t sMa = analogRead(A5);
  uint16_t sVal;
  for (int i = 0; i < 100; i++) {
    sVal = analogRead(A5);
    sMi = min(sMi, sVal);
    sMa = max(sMa, sVal);
  }
  // uint16_t x = analogRead(A5); // Low is 56, High is 4125 if done manually
  analogWrite(D5, map(sVal, sMi, sMa, 0, 255));
}