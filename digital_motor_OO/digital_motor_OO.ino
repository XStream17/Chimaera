#include "uart.h"
#include "motor.h"


uart bluetooth (96,'z');
motor *dir (5,6,10,9);
void setup() {
  // put your setup code here, to run once:
   bluetooth.initialize();
   dir->motor_init(5,6,10,9);

}

void loop() {
  // put your main code here, to run repeatedly:
  char char_data = bluetooth.receive_char();
  dir->control(char_data);
  
}
