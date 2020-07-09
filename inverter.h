//inverter.h
#include "Arduino.h";

#ifndef INVERTER_H
#define INVERTER_H

#define ON   1
#define OFF  0
#define CW   0
#define CCW  1

class Motor {
public :
	//pin
	int on_pin;
	int rw_pin; 
	int speed_pin;
	//speed (default : 0 ~ 60)
	int max_speed = 60;
	int cur_speed = 0;
	//direction
	char cw = 0;
	
public :
	//p1 p2 vr1
	Motor(int on_pin, int rw_pin, int speed_pin) {
		this->on_pin = on_pin;
		this->rw_pin = rw_pin;
		this->speed_pin = speed_pin;
		pinMode(on_pin, OUTPUT);
		pinMode(rw_pin, OUTPUT);
		pinMode(speed_pin, OUTPUT);
	}
	void set_speed(int speed) {
		this->cur_speed = speed;
		analogWrite(speed_pin, 255 * cur_speed / max_speed);
	}
	void set_cw(int cw) {
		this->cw = cw;
		digitalWrite(rw_pin, cw);
	}

	void drive() {
		digitalWrite(this->on_pin, 1);
	}
	void drive(int onoff) {
		analogWrite(speed_pin, cur_speed * max_speed / 5);
		digitalWrite(on_pin, onoff);
	}
	void drive(int onoff, int cw) {
		set_cw(cw);
		drive(onoff);
	}
	void drive(int onoff, int cw, int speed) {
		set_cw(cw);
		set_speed(speed);
		drive(onoff);
	}
};

#endif 