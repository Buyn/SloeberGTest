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
	void move(int);
	void set_speed(int);
	void set_enable(int);
	void set_steps(void );
	void update(void );
	void runtime(void );
	bool done(void);
	void on(void );
	void off(void );
	/*}}}*/
	/* private: * {{{*/
#ifndef UNITTEST/*{{{*/
 private:
#endif /* UNITTEST }}}*/
	unsigned long update_time;
	int pin;
	bool enable;
	unsigned int value;
	unsigned long timeout;
	void step(void);
	/*}}}*/
 };
 /*}}}*/
#endif
