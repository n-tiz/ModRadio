#include <Arduino.h>
#include "Program.hh"

Program _program = Program();

void setup()
{
  _program.Initialize();
}

void loop()
{
  _program.Update();

  delay(10);
}
