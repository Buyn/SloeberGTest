#include "StepMotor.h"

/*   StepMotor::StepMotor   * {{{ */
StepMotor::StepMotor(int _pin) {
	pin = _pin;
	to_value = 0;
	value = 0;
	fade_speed = 10;
	update_time = millis() + fade_speed;
	pinMode(pin, OUTPUT);
	} //}}}
/*   StepMotor::StepMotor   * {{{ */
StepMotor::StepMotor() {
	pin = 0;
	to_value = 0;
	value = 0;
	fade_speed = 10;
	update_time = millis() + fade_speed;
	} //}}}

/*   StepMotor::set_speed   * {{{ */
void StepMotor::set_speed(int new_speed){
	fade_speed = new_speed;
	} //}}}

/*   StepMotor::fade_to   * {{{ */
void StepMotor::fade_to(int new_value){
	to_value = new_value;
	} //}}}

/*   StepMotor::set_to   * {{{ */
void StepMotor::set_to(int new_value){
	to_value = new_value;
	value = new_value;
	set_on();
	} //}}}

/*   StepMotor::set_on   * {{{ */
void StepMotor::set_on(void){
	analogWrite(pin, to_value);
	} //}}}

/*   StepMotor::update   * {{{ */
void StepMotor::update(void){
	if ( value > to_value) fade_Down();
	if ( value < to_value) fade_Up();
	} //}}}

/*   StepMotor::runtime   * {{{ */
void StepMotor::runtime(void){
	if (millis() < update_time) return;
	if ( value != to_value ) update();
	update_time = millis() + fade_speed;
	} //}}}
/*   StepMotor::done   * {{{ */
bool StepMotor::done(void){
	if ( value == to_value ) return true;
	else return false;
	} //}}}

/*   StepMotor::fade_Up   * {{{ */
void StepMotor::fade_Up(void){
	if ( value == StepMotor_MAX_VALUE) return;
	analogWrite(pin, value++);
	//value++;
	} //}}}

/*   StepMotor::fade_Down   * {{{ */
void StepMotor::fade_Down(void){
	if ( value == 0) return;
	analogWrite(pin, value--);
	//to_value--;
	} //}}}

/*   StepMotor::on   * {{{ */
void StepMotor::on(void) {
	digitalWrite(pin, HIGH);
	} //}}}
/*   StepMotor::off   * {{{ */
void StepMotor::off(void) {
	digitalWrite(pin, LOW);
	} //}}}
/*   StepMotor::trige   {{{ */
void StepMotor::trige(void) {
	if (value == 0) {
		on();
		value = 1;
		}
	else{
		off();
		value = 0;
		}
	} //}}}



