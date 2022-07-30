//ESp32 test code
//Toggles led state present at pin 33 every one second


int led_pin = 33;


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
