#ifdef UNITTEST
#include "gtest.h"
#include "stepmotor.h"


TEST(stepmotor, init) {
	StepMotor sm = StepMotor(2);
	EXPECT_EQ(sm.pin,2);
	EXPECT_EQ(sm.value,0);
	}

TEST(stepmotor, Step) {
	StepMotor sm = StepMotor(2);
	sm.move(100);
	EXPECT_EQ(sm.value,100);
	sm.step();
	EXPECT_EQ(sm.value,99);
	sm.step();
	EXPECT_EQ(sm.value,98);
	sm.move(100);
	EXPECT_EQ(sm.value,198);
	}

TEST(stepmotor, runtime) {
//	EXPECT_EQ(dist1, dist1_1.distance(dist1_2));
	}

TEST(stepmotor, setspeed) {
//	EXPECT_EQ(dist1, dist1_1.distance(dist1_2));
	}


#endif
