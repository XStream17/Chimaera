#include "uart.h"
#include "sg90.h"
#include "motor.h"

uart bluetooth (96,'z');
claw claw1(11);
motor m1(5,6,10,9);
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  bluetooth.initialize();
  claw1.init();
} 
 
 
void loop() 
{ 
  char char_data = 0;
  char_data = bluetooth.receive_char();
  m1.control(char_data);
  if (char_data != 0)
    Serial.write(char_data);
  claw1.whentograb(char_data);
} 

