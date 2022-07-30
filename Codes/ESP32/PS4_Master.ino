#include <PS4Controller.h>

#define led_pin 33

char ack = 6;
int x = 0;
int y = 0;
int z = 0;

long data_rate = 20;
long prev_time = 0;
long current_time = 0;

byte led = 0;

//---------------------------------------------------------------------------------------------------//

void setup()
{
  Serial.begin(115200);
  PS4.begin("48:5f:99:09:76:b2");  //MAC address of your PS4
  pinMode(led_pin, OUTPUT);
}

//---------------------------------------------------------------------------------------------------//

void loop()
{
  current_time = millis();

  readValues(); // Get data from PS4

  if (current_time - prev_time > data_rate)
  {
    sendValues(); //Send data to Atmega328
    //printValues(); //Prints data on serial port of debugging

    led = !led;
    digitalWrite(led_pin, led);

    prev_time = current_time;
  }
}

//---------------------------------------------------------------------------------------------------//

void readValues()
{
  x = PS4.LStickX();
  y = PS4.LStickY();
  z = PS4.RStickX(); //rotation
}

//---------------------------------------------------------------------------------------------------//

void sendValues()
{
  Serial.print(ack);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
}

//---------------------------------------------------------------------------------------------------//

void printValues()
{
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(z);
}

//---------------------------------------------------------------------------------------------------//
