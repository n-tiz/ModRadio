#include <Arduino.h>
#include "Program.hh"

Program _program = Program();

void setup()
{
  Serial.begin(9600);
  _program.Initialize();
}

void loop()
{
  _program.Update();
  delay(10);
}
