#ifdef UNITTEST

#include "gtest.h"
#include "shiftout.h"


TEST(Spi, startSessio) {/*{{{*/
//	<< "Hello World!";
//	std::cerr << "[          ] random seed";
	ShiftOut leds;
//	EXPECT_FALSE(false)<<"false form start";
	EXPECT_EQ(leds.send16(1), 0);
	EXPECT_EQ(leds.send16(2), 0);
	EXPECT_EQ(leds.send16(9), 0);
	EXPECT_EQ(leds.send16(16), 1);
	EXPECT_EQ(leds.send16(255), 1);
//	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
//	EXPECT_FALSE(sspi.spi_sesion)<<"false from sesion end";
	}/*}}}*/




#endif
