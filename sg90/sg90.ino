#include <Servo.h> 
#include "sg90.h" 
#include "uart.h"

uart bluetooth (96,'z');
sg90 *claw (11);
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  bluetooth.initialize();
  claw->sg90_init(11);
} 
 
 
void loop() 
{ 
  char char_data = bluetooth.receive_char();
  claw->whentograb(char_data);
} 
