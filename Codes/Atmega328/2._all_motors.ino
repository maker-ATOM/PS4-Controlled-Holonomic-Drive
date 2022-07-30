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

//-------------------------------------------------------------------------------------//

#define m1_pow 6
#define m1_dir 7
#define m1_en 8

#define m2_pow 3
#define m2_dir 2
#define m2_en 4

#define m3_pow 9
#define m3_dir 19
#define m3_en 16

#define m4_pow 10
#define m4_dir 17
#define m4_en 18

#define led 15

byte motor_pow = 50;

//-------------------------------------------------------------------------------------//

void setup()
{
  pinMode(m1_pow, OUTPUT);
  pinMode(m1_dir, OUTPUT);
  pinMode(m1_en, OUTPUT);

  pinMode(m2_pow, OUTPUT);
  pinMode(m2_dir, OUTPUT);
  pinMode(m2_en, OUTPUT);

  pinMode(m3_pow, OUTPUT);
  pinMode(m3_dir, OUTPUT);
  pinMode(m3_en, OUTPUT);

  pinMode(m4_pow, OUTPUT);
  pinMode(m4_dir, OUTPUT);
  pinMode(m4_en, OUTPUT);

  pinMode(led, OUTPUT);

  digitalWrite(m1_en, LOW);
  digitalWrite(m2_en, LOW);
  digitalWrite(m3_en, LOW);
  digitalWrite(m4_en, LOW);
}

//-------------------------------------------------------------------------------------//

void loop()
{
  digitalWrite(m1_en, HIGH);
  M1_test();
  digitalWrite(m1_en, LOW);
  delay(250);

  digitalWrite(m2_en, HIGH);
  M2_test();
  digitalWrite(m2_en, LOW);
  delay(250);

  digitalWrite(m3_en, HIGH);
  M3_test();
  digitalWrite(m3_en, LOW);
  delay(250);

  digitalWrite(m4_en, HIGH);
  M4_test();
  digitalWrite(m4_en, LOW);
  delay(250);

}

//-------------------------------------------------------------------------------------//

void M1_test()
{
  digitalWrite(m1_dir, HIGH);
  analogWrite(m1_pow, 255 - motor_pow);
  delay(1500);
  digitalWrite(m1_dir, LOW);
  analogWrite(m1_pow, motor_pow);
  delay(1500);
}

void M2_test()
{
  digitalWrite(m2_dir, HIGH);
  analogWrite(m2_pow, 255 - motor_pow);
  delay(1500);
  digitalWrite(m2_dir, LOW);
  analogWrite(m2_pow, motor_pow);
  delay(1500);
}

void M3_test()
{
  digitalWrite(m3_dir, HIGH);
  analogWrite(m3_pow, 255 - motor_pow);
  delay(1500);
  digitalWrite(m3_dir, LOW);
  analogWrite(m3_pow, motor_pow);
  delay(1500);
}

void M4_test()
{
  digitalWrite(m4_dir, HIGH);
  analogWrite(m4_pow, 255 - motor_pow);
  delay(1500);
  digitalWrite(m4_dir, LOW);
  analogWrite(m4_pow, motor_pow);
  delay(1500);
}

//-------------------------------------------------------------------------------------//
