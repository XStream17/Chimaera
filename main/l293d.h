/*{l293d. This is the class that allow arduino to interact with l293d to control the dc motor used}
    Copyright (C) {2017}  {XSTREAM17}

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

/*
	A)SYNTAX:
		motor ObjectName (pin1, pin2, pin3, pin4)
		
		pin1 to pin4 is the pin number where your l293d connected to arduino
	
	B) AVAILABLE FUNCTION (FUNCTION PROTOCOL);
		void control(char char_data);
*/


class l293d
{
   /******************
   * INITIALIZATION *
   ******************/
  /* Public function used for OBJECT DECLARATION */
  public:
  /* Initialization for safety purpose
   * Value to be replaced when declared */
  int driver1Pin;
  int driver2Pin;
  int driver3Pin;
  int driver4Pin;
	  
	//Public function used for object declaration
	l293d(int pin1, int pin2, int pin3, int pin4) : driver1Pin(pin1) ,driver2Pin(pin2) , driver3Pin(pin3), driver4Pin(pin4) 
	  {
		pinMode(driver1Pin, OUTPUT);
		pinMode(driver2Pin, OUTPUT);
		pinMode(driver3Pin, OUTPUT);
		pinMode(driver4Pin, OUTPUT);
	  }
	  
	  
	  
  // function where we receive data from bluetooth and we active different function to allow the robot to perform as needed
  void control(char char_data)    //controlling the motor
  {
    switch(char_data){
    case 'F':                     //Forward
    digitalWrite(driver1Pin, HIGH);  
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, HIGH);
    digitalWrite(driver4Pin, LOW);
    delay(50);
    break;
    case 'B':                     //Backward
    digitalWrite(driver1Pin, LOW);  
    digitalWrite(driver2Pin, HIGH);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, HIGH);
    delay(50);
    break;
    case 'L':                     //Left
    digitalWrite(driver1Pin, HIGH);  
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, HIGH);
    delay(50); 
    break;
    case 'R':                     //Right
    digitalWrite(driver1Pin, LOW);  
    digitalWrite(driver2Pin, HIGH);
    digitalWrite(driver3Pin, HIGH);
    digitalWrite(driver4Pin, LOW);
    delay(50); 
    break;
    case 'Z':                     //Stop
    digitalWrite(driver1Pin, LOW);
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, LOW);
    delay(50);
    break;
    default:
    break;
  }
  }
};
