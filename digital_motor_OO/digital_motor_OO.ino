#include "uart.h"
#include "motor.h"

uart bluetooth(96,'z');
motor m1(5,6,10,9);

void setup() {
  // put your setup code here, to run once:
   bluetooth.initialize();

}

void loop() {
  // put your main code here, to run repeatedly:
  char char_data = 0;
  char_data = bluetooth.receive_char();
  m1.control(char_data);
  
}
