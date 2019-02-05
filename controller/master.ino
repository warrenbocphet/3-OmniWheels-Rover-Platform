#include <Wire.h>

struct speed {
	byte send_speed_low;
	byte send_speed_high;
	byte send_speed_dir;
};

void oneint2bytes(int speed_int, struct speed* speed) {
	if (speed_int < 0)	{
		speed_int = speed_int*-1;
		speed->send_speed_low = speed_int & 0xFF;
		speed->send_speed_high = (speed_int >> 8) & 0xFF;
		speed->send_speed_dir = 1;

	} else {
		speed->send_speed_low = speed_int & 0xFF;
		speed->send_speed_high = (speed_int >> 8) & 0xFF;
		speed->send_speed_dir = 3;
	}
}

void send_speed(int speed0_int, int speed1_int, int speed2_int)	{
	struct speed speed0;
	struct speed speed1;
	struct speed speed2;

	byte buf[9];

	oneint2bytes(speed0_int, &speed0);
	oneint2bytes(speed1_int, &speed1);
	oneint2bytes(speed2_int, &speed2);

	buf[0] = speed0.send_speed_high;
	buf[1] = speed0.send_speed_low;
	buf[2] = speed0.send_speed_dir;

	buf[3] = speed1.send_speed_high;
	buf[4] = speed1.send_speed_low;
	buf[5] = speed1.send_speed_dir;

	buf[6] = speed2.send_speed_high;
	buf[7] = speed2.send_speed_low;
	buf[8] = speed2.send_speed_dir;

	Wire.beginTransmission(97); // transmit to device #97
	Wire.write(buf, 9);
	Wire.endTransmission();
}

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  
}
