# arduino-inverter_driver
inverter driver

## 헤더파일 추가
~~~c++
#include <inverter.h>
~~~
헤더파일은 document/Arduino/libraries/inverter_driver 폴더를 만들고 안에 넣어야함

## Motor 생성
~~~c++
int on_pin    = 0
int cw_pin    = 1
int speed_pin = 2

Motor motor(on_pin, cw_pin, speed_pin);
~~~
on_pin(p1), cw_pin(p2), speed_pin(V1)을 각각 넣어준다

## Motor.set_speed(int speed)
~~~c++
moter.set_speed(30);
~~~
motor의 회전 속도를 정해준다
default는 60Hz이다

## Motor.set_cw(int cw)
~~~c++
motor.set_cw(CW)  // == motor.set_cw(0);
motor.set_cw(CCW) // == motor.set_cw(1);
~~~
motor의 회전 방향을 정해준다
default는 CW이다

## Motor.drive()
~~~c++
motor.drive();
~~~
모터 운전을 시작한다

## Motor.drive(int onoff)
~~~c++
motor.drive(ON);  // == motor.drive(1);
motor.drive(OFF); // == motor.drive(0);
~~~
모터를 키고 끈다

## Motor.drive(int onoff, int cw)
~~~c++
motor.drive(ON, CW);   // 모터 회전 방향을 CW로 하고 동작시킴
motor.drive(OFF, CCW); // 모터 회전방향을 CCW로 하고 동작을 정지함
~~~
모터의 회전 방향을 선택하고 키거나 끈다
