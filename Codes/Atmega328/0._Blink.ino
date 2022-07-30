//Atmega328p test code
//Toggles led state present at pin 15 (A1) every one second

int led_pin = 15;

void setup()
{
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(1000);
}
