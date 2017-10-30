#include "uart.h"
#include "sg90.h"

uart bluetooth (96,'z');
claw claw1(11);
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  bluetooth.initialize();
  claw1.init();
} 
 
 
void loop() 
{ 
  char char_data = bluetooth.receive_char();
  if (char_data != 0)
    Serial.write(char_data);
  claw1.whentograb(char_data);
} 
