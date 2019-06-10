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
	pinMode(LED_BUILTIN, OUTPUT);
}
/*}}}*/
void Blink::test_loop() {/*{{{*/
	static uint8_t ledState = LOW;
	digitalWrite(LED_BUILTIN, ledState);
}
/*}}}*/
