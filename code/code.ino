<<<<<<< HEAD
//<FIXME> add config.h and header.h


=======
>>>>>>> c557828bced59eaa0cc7524471de557d10d29534
#include "header.h"

bluetooth *b1;
claw *claw1;
l293d *m1;
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  b1 = new bluetooth(96,'z');
  claw1 = new claw(11);
  m1 = new l293d(5,6,10,9);
}
 
 
void loop() 
{ 
  char char_data = 0;
  char_data = b1->receive_char();
  m1->control(char_data);
  if (char_data != 0)
    Serial.write(char_data);
  claw1->whentograb(char_data);
} 

