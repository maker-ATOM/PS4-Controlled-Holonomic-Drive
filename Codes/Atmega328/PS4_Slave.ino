/*             M3                                      M1
          |-------|                               |-------|
          |       |                               |       |
          |       |-------------------------------|       |
          |       |                               |       |
          |-------|                               |-------|
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
                                  |
             M4                   |                   M2
          |-------|                               |-------|
          |       |               F               |       |
          |       |-------------------------------|       |
          |       |                               |       |
          |-------|                               |-------|
*/

#define m1_pow_pin 6
#define m1_dir_pin 7
#define m1_en_pin 8

#define m2_pow_pin 3
#define m2_dir_pin 2
#define m2_en_pin 4

#define m3_pow_pin 9
#define m3_dir_pin 19
#define m3_en_pin 16

#define m4_pow_pin 10
#define m4_dir_pin 17
#define m4_en_pin 18

#define led_pin 15

#define buzzer_pin 5

int m1_pow = 0;
byte m1_dir = 0;

int m2_pow = 0;
byte m2_dir = 0;

int m3_pow = 0;
byte m3_dir = 0;

int m4_pow = 0;
byte m4_dir = 0;

int x = 0;
int y = 0;
int z = 0; //rotation

byte led = 0;

int battery = 0;

//---------------------------------------------------------------------------------------------------//

void setup()
{
  Serial.begin(115200);

  pinMode(m1_pow_pin, OUTPUT);
  pinMode(m1_dir_pin, OUTPUT);
  pinMode(m1_en_pin, OUTPUT);

  pinMode(m2_pow_pin, OUTPUT);
  pinMode(m2_dir_pin, OUTPUT);
  pinMode(m2_en_pin, OUTPUT);

  pinMode(m3_pow_pin, OUTPUT);
  pinMode(m3_dir_pin, OUTPUT);
  pinMode(m3_en_pin, OUTPUT);

  pinMode(m4_pow_pin, OUTPUT);
  pinMode(m4_dir_pin, OUTPUT);
  pinMode(m4_en_pin, OUTPUT);

  digitalWrite(m1_en_pin, HIGH);
  digitalWrite(m2_en_pin, HIGH);
  digitalWrite(m3_en_pin, HIGH);
  digitalWrite(m4_en_pin, HIGH);

  pinMode(led_pin, OUTPUT);

  pinMode(buzzer_pin, OUTPUT);

  delay(2000); //let everything settle down
}

//---------------------------------------------------------------------------------------------------//

void loop()
{

  readValues();       // Get values from ESP32
  calculateValues();  // Calculate direction and PWM of each motor
  driveMotors();      // Driver each motor

  battery = analogRead(A0);

  //If battery level is below 9.6V shut down the main operation and beep continously
  if (battery < 750)
  {
    beepBuzzer();
  }
}

//---------------------------------------------------------------------------------------------------//

void readValues()
{
  if (Serial.read() == 6)
  {
    x = Serial.parseInt();
    y = Serial.parseInt();
    z = Serial.parseInt();

    led = !led;
    digitalWrite(led_pin, led);
  }
}

//---------------------------------------------------------------------------------------------------//

void calculateValues()
{
  //should be multiplied by 2 for full power utilization
  m1_pow = (y - x - z);
  m2_pow = (x + y - z);
  m3_pow = (x + y + z);
  m4_pow = (y - x + z);

  m1_pow = constrain(m1_pow, -255, 255);
  if (m1_pow > 0)
  {
    m1_dir = 1;
    m1_pow = 255 - m1_pow;
  }
  else
  {
    m1_dir = 0;
    m1_pow = abs(m1_pow);
  }

  m2_pow = constrain(m2_pow, -255, 255);
  if (m2_pow > 0)
  {
    m2_dir = 0;
  }
  else
  {
    m2_dir = 1;
    m2_pow = 255 + m2_pow;
  }

  m3_pow = constrain(m3_pow, -255, 255);
  if (m3_pow > 0)
  {
    m3_dir = 0;
  }
  else
  {
    m3_dir = 1;
    m3_pow = 255 + m3_pow;
  }

  m4_pow = constrain(m4_pow, -255, 255);
  if (m4_pow > 0)
  {
    m4_dir = 1;
    m4_pow = 255 - m4_pow;
  }
  else
  {
    m4_dir = 0;
    m4_pow = abs(m4_pow);
  }
}

//---------------------------------------------------------------------------------------------------//

void driveMotors()
{
  digitalWrite(m1_dir_pin, m1_dir);
  analogWrite(m1_pow_pin, m1_pow);

  digitalWrite(m2_dir_pin, m2_dir);
  analogWrite(m2_pow_pin, m2_pow);

  digitalWrite(m3_dir_pin, m3_dir);
  analogWrite(m3_pow_pin, m3_pow);

  digitalWrite(m4_dir_pin, m4_dir);
  analogWrite(m4_pow_pin, m4_pow);
}

//---------------------------------------------------------------------------------------------------//

void beepBuzzer()
{
  for (;;)
  {
    tone(buzzer_pin, 1700);
    delay(250);
    led = !led;
    digitalWrite(led_pin, led);
    noTone(buzzer_pin);
    delay(250);
    led = !led;
    digitalWrite(led_pin, led);
  }
}

//---------------------------------------------------------------------------------------------------//
