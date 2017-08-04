#define break_char '\0'

void bluetooth_config(void)
{
	Serial.begin(9600);
}

void bluetooth_receive(void)
{
	char data;
	int xvalue = 0;
	int yvalue = 0;

	if (Serial.available() > 0)
	{
		data = Serial.read();
	}

	//Additional function
	switch (data)
	{
	case 'x': xvalue = get_value();
	case 'y': yvalue = get_value();
	}

}

int get_value(void)
{
	char receivevalue = '0';
	int value = 0;
	while (receivevalue != break_char)
	{
		value = value * 10;
		receivevalue -= 47;
		value += receivevalue;
		receivevalue = Serial.read();
	}

	return value;
}