#ifdef UNITTEST

#include "gtest.h"
#include "Stack.h"
#include "slavespi.h"

TEST(Spi, startSessio) {/*{{{*/
	SlaveSPI sspi(8);
	EXPECT_FALSE(sspi.spi_sesion)<<"false form start";
	EXPECT_EQ(sspi.spiaddress, 8);
	sspi.setmsg(8);
	sspi.testmsg(8);
	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
	sspi.setmsg(ENDOFSESION);
	sspi.testmsg(ENDOFSESION);
	EXPECT_FALSE(sspi.spi_sesion)<<"false from sesion end";
	}/*}}}*/

TEST(Spi, command_stack) {/*{{{*/
	SlaveSPI sspi(8);
	sspi.setmsg(8);
	sspi.testmsg(8);
	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
	sspi.setmsg(2);
	sspi.testmsg(2);
	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
	sspi.setmsg(8);
	sspi.testmsg(8);
	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
	EXPECT_EQ(sspi.peek(), 8);
	EXPECT_EQ(sspi.pull(), 8);
	EXPECT_NE(sspi.peek(), 8);
	sspi.testmsg(8);
	sspi.setmsg(ENDOFSESION);
	sspi.testmsg(ENDOFSESION);
	EXPECT_FALSE(sspi.spi_sesion)<<"false from sesion end";
	}/*}}}*/

TEST(Spi, msg_stack_get_one) {/*{{{*/
	SlaveSPI sspi(8);
	sspi.setmsg(8);
	sspi.testmsg(8);
	EXPECT_EQ(sspi.staksize(), 0);
	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
	sspi.setmsg(SC_ISMSGWATING);
	sspi.testmsg(SC_ISMSGWATING);
	EXPECT_EQ(sspi.back_msg, 0);
	EXPECT_EQ(sspi.staksize(), 0);
	sspi.addMSG(10,20);
	sspi.setmsg(SC_ISMSGWATING);
	sspi.testmsg(SC_ISMSGWATING);
	EXPECT_EQ(sspi.back_msg, 2);
	EXPECT_EQ(sspi.staksize(), 0);
	EXPECT_TRUE(sspi.spi_sesion)<<"turue if sesion starteted";
	sspi.setmsg(SC_GETMSGBYCOUNT);
	sspi.testmsg(SC_GETMSGBYCOUNT);
	EXPECT_EQ(sspi.back_msg, 20);
	EXPECT_EQ(sspi.staksize(), 0);
	sspi.setmsg(0);
	sspi.testmsg(0);
	EXPECT_EQ(sspi.back_msg, 10);
	sspi.setmsg(SC_ISMSGWATING);
	sspi.testmsg(SC_ISMSGWATING);
	EXPECT_EQ(sspi.back_msg, 0);
	sspi.setmsg(ENDOFSESION);
	sspi.testmsg(ENDOFSESION);
	EXPECT_FALSE(sspi.spi_sesion)<<"false from sesion end";
	}/*}}}*/
#endif
