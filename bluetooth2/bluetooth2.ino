#include "uart.h"
uart bluetooth (96,'z');
void setup() {
  // put your setup code here, to run once:
   bluetooth.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
 bluetooth.test();

}
