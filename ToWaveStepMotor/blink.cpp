/*{{{
 * blink.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 *//*}}}*/
/*include block {{{*/
#include "blink.h"
/*}}}*/
void Blink::test_setup() {/*{{{*/
	//sm = ToWaveStepMotor(2);
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(STEP_PIN, OUTPUT);
	sm.set_longs(STEP_LONGS);
	sm.set_timeout(STEP_TIMEOUT);
}
/*}}}*/
void Blink::test_loop() {/* {{{*/
	sm.runtime();
	if(sm.done()){
		digitalWrite(LED_BUILTIN, HIGH);
		delay(SERIES_TIMEOUT);
		digitalWrite(LED_BUILTIN, LOW);
		sm.move(SERIES_PULSES);
		}
	}
	/*}}}*/
