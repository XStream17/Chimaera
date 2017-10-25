/*{arduino_HC-05. This is the class that help arduino to interact with HC-05}
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
	
	//remember to change uart
class uart
{
  //class member variable
  //they are initialized immediately after startup
  unsigned int baud_rate = 0; //baud rate of bluetooth and arduino
  char break_char = 0; //ending character
  
  
  // constructor - creates a bluetooth and initializes the member variables and state
  public:
  uart(unsigned int BaudRateDivide100, char ending_command)
  {
    baud_rate = BaudRateDivide100;
    break_char = ending_command;
  }

  void initialize()
  {
    Serial.begin(baud_rate * 100);
  }

  char receive_char()
  {
    char char_data = 0;
    
    if (Serial.available() > 0)    
      char_data = Serial.read();

    return char_data;
  }

  char receive_int()
  {
    int int_data = 0;
    
    if (Serial.available() > 0)    
      int_data = Serial.read();

    return int_data;
  }
  
  int receive_value()
  {
    int value = 0;
    char receivevalue = '0';

    while (receivevalue != break_char)
    {
      value = value * 10;
      receivevalue -= 48;
      value += receivevalue;
      receivevalue = Serial.read();
    }

    return value;
  }

  void send_char(char send_data)
  {
    Serial.write(send_data);
  }

  void test()
  {
    char test_data = 0;
    
    if (Serial.available() > 0)
    {
      test_data = Serial.read();
      Serial.write(test_data);
    }
  }
};
