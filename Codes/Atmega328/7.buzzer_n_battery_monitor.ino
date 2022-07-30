#define buzzer_pin 5

int battery = 0;


byte led = 1;

void setup()
{
  Serial.begin(115200);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);
  delay(1500);
  digitalWrite(15, LOW);
  delay(1500);
  digitalWrite(15, HIGH);

  delay(1500);
  digitalWrite(15, LOW);
  delay(1500);
}

void loop()
{
  battery = analogRead(A0);
  Serial.println(battery);
  //voltage on analog pin at threshold which is set at 3.1V each call = 9.3V overall is equal to
  //9.9 * (30K / (30K + 10K)) considering R1 = 30K and R2 = 10K which is 2.475V
  //when voltage less than 2.475V is detected by the system the buzzer should beep continously
  //the reference voltage given is 3.3V from ESP32 so 3.3V maps to 1023 of ADC and 2.475V maps to
  //1023 * 2.475 / 3.3 = 765

  if (battery < 750)
  {
    beepBuzzer();
  }
  digitalWrite(15, HIGH);
}

void beepBuzzer()
{
  for (;;)
  {
    tone(5, 1700);
    delay(250);
    led = !led;
    digitalWrite(15, led);
    noTone(5);
    delay(250);
    led = !led;
    digitalWrite(15, led);
  }
}
