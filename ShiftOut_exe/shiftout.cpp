#include "ShiftOut.h"

/*   ShiftOut::ShiftOut   * {{{ */
ShiftOut::ShiftOut(void) {
	} //}}}

/*   ShiftOut::initpins   * {{{ */
void ShiftOut::initpins(void){
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
	} //}}}

/*   ShiftOut::send16   * {{{ */
bool ShiftOut::send16(BYTES_VAL_T value){
	if (value == oldPinValues) return false;
#ifdef UNITTEST/*{{{*/
	std::cerr << "\n Start new test:";
	for ( int i=0 ; i < 16 ; i++ ) {/*{{{*/
		std::cerr << "\n pin "<<i <<" : ";
		std::cerr  << !!(value & (1 << i));
		}/*}}}*/
	std::cerr << "\n End of test:";
	return  !!(value & (1 << 4));
#endif /* UNITTEST }}}*/
	#ifndef UNITTEST/*{{{*/
	// устанавливаем синхронизацию "защелки" на LOW
	digitalWrite(latchPin, LOW);
	for ( int i=0 ; i < 16 ; i++ ) {/*{{{*/
		digitalWrite( ulDataPin, !!(value & (1 << i)) ) ;
		digitalWrite( ulClockPin, HIGH ) ;
		digitalWrite( ulClockPin, LOW ) ;		
		}/*}}}*/
	//"защелкиваем" регистр, тем самым устанавливая значения на выходах
	digitalWrite(latchPin, HIGH);
	oldPinValues = value;
	return true;
	#endif /* UNITTEST }}}*/
	} //}}}

/* display_pin_values {{{
Dump the list of zones along with their current status.
*/
void ShiftOut::display_pin_values() {
    Serial.print("Pin States:\r\n");
    for(int i = 0; i < DATA_WIDTH; i++) {/*{{{*/
       Serial.print("  Pin-");
       Serial.print(i);
       Serial.print(": ");
       if((oldPinValues >> i) & 1)
           Serial.print("HIGH");
       else
           Serial.print("LOW");

       Serial.print("\r\n");
		 }/*}}}*/
    Serial.print("\r\n");
	}/*}}}*/

