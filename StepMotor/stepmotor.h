/* coment bloc  {{{
 *
 * Step motor class 
 * to control singl Step Motor driver
***************************************
***************************************
 *  }}}*/
/* include bloc {{{*/
#ifndef StepMotor_h
#define StepMotor_h
// the #include statment and code go here...
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
/*}}}*/
//define bloc  {{{
#define StepMotor_MAX_VALUE 255
/*}}}*/
// encounter calss{{{
class StepMotor {
 public: // {{{
	StepMotor(int );
	StepMotor();
	void set_speed(int);
	void fade_to(int);
	void set_to(int);
	void update(void );
	void runtime(void );
	bool done(void);
	void on(void );
	void off(void );
	void trige(void );
	unsigned long update_time;
	int pin;
	/*}}}*/
 private:/*{{{*/
	unsigned int value, to_value;
	unsigned long fade_speed;
	void fade_Up(void); 
	void fade_Down(void); 
	void set_on(void); 
	/*}}}*/
 };
 /*}}}*/
#endif
