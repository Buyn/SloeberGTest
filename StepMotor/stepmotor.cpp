#include "StepMotor.h"

/*   StepMotor::StepMotor   * {{{ */
StepMotor::StepMotor(int _pin) {
	pin 			= _pin;
	value 		= 0;
	timeout	 	= 10;
	update_time = millis() + timeout;
	pinMode(pin, OUTPUT);
	} //}}}
/*   StepMotor::StepMotor   * {{{ */
StepMotor::StepMotor() {
	pin = 0;
	value = 0;
	timeout = 10;
	update_time = millis() + timeout;
	} //}}}

/*   StepMotor::set_speed   * {{{ */
void StepMotor::set_speed(int new_speed){
	timeout = new_speed;
	} //}}}
/*   StepMotor::move   * {{{ */
void StepMotor::move(int new_value){
	value += new_value;
	} //}}}

/*   StepMotor::set_enable   * {{{ */
void StepMotor::set_enable(int new_value){
	if (new_value == 0) {
		enable = false;
	}else{	
		enable = true;
		}
	} //}}}

/*   StepMotor::update   * {{{ */
void StepMotor::update(void){
	if ( value != 0) step();
	} //}}}

/*   StepMotor::runtime   * {{{ */
void StepMotor::runtime(void){
	if (millis() < update_time) return;
	if ( value != 0 ) update();
	update_time = millis() + timeout;
	} //}}}
/*   StepMotor::done   * {{{ */
bool StepMotor::done(void){
	if ( value == 0 ) return true;
	else return false;
	} //}}}

/*   StepMotor::step   * {{{ */
void StepMotor::step(void){
	if ( value == 0) return;
	analogWrite(pin, HIGH);
	value--;
	analogWrite(pin, LOW);
	} //}}}

/*   StepMotor::on   * {{{ */
void StepMotor::on(void) {
	digitalWrite(pin, HIGH);
	} //}}}
/*   StepMotor::off   * {{{ */
void StepMotor::off(void) {
	digitalWrite(pin, LOW);
	} //}}}



