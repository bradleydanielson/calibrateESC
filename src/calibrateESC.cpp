#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "mraa.h"
#include "SparkFun_pca9685_Edison.h"

// Definitions
#define motorN 0
#define motorS 1
#define motorE 2
#define motorW 3
#define pwmFreq 550

using namespace std;

mraa::I2c* pwm_i2c;


int main() {

	pwm_i2c = new mraa::I2c(1) ;
	float fullthrottle = 100.0 ;
	float nothrottle = 0.0 ;
	int checkForOne = 0 ;

	pca9685 pwm(pwm_i2c, 0x40);
	pwm.setFreq(pwmFreq) ; // Sets PWM Freq to 600 Hz
	sleep(1) ;
	pwm.setFourMotors(fullthrottle) ;

	while (checkForOne != 1){
		cout << "All motors are now 100% duty cycle" << endl ;
		cout << "Enter 1 After prompt from ESC and hit enter" << endl ;
		cin >> checkForOne ;
	}

	checkForOne = 0 ;
	pwm.setFourMotors(nothrottle) ;

	while (checkForOne != 1){
		cout << "All Motors are no zero duty cycle"<< endl ;
		cout << "Enter 1 After prompt from ESC and hit enter" << endl ;
		cin >> checkForOne ;
	}

   return 0;
}
