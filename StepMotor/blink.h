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
/*{{{*/
#define INTERVAL 500 //The blinking interval
/*}}}*/
/*Varibls block{{{*/

/*}}}*/
//void test_setup(void);
//void test_loop(void);
class Blink {//{{{
 public: // {{{
	void test_setup(void);
	void test_loop(void);
	int itest;
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
