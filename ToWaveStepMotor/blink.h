/*{{{
 * blink.h
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 *//*}}}*/

#ifndef BLINK_H_/*{{{*/
#define BLINK_H_
#include "Arduino.h"
#include "ToWaveStepMotor.h"
#include "defcfg.h"
/*Define block{{{*/
#define STEP_TIMEOUT		500
#define STEP_LONGS		500
#define SERIES_TIMEOUT		10000
#define SERIES_PULSES		500
#define STEP_PIN		A0
#define LED_BUILTIN 	13
/*}}}*/
class Blink {//{{{
 public: // {{{
	void test_setup(void);
	void test_loop(void);
	/*Varibls block{{{*/
	ToWaveStepMotor sm = ToWaveStepMotor(STEP_PIN);
	/*}}}*/
	/*}}}*/
	/* private: * {{{*/
#ifndef UNITTEST/*{{{*/
 private:
#endif /* UNITTEST }}}*/
	/*}}}*/
 };
 /*}}}*/

#endif /* BLINK_H_ }}}*/
//Added by Sloeber 
#pragma once
