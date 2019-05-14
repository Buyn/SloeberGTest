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
	void move(long);
	void set_speed(int);
	void set_enable(int);
	void resetimer(void);
	void stop(void);
	void stop(long);
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
	unsigned long update_time, value;
	int pin;
	bool enable;
	unsigned long timeout;
	void step(void);
	/*}}}*/
 };
 /*}}}*/
#endif
