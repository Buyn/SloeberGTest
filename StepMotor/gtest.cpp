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

TEST(stepmotor, setspeed) {
	StepMotor sm = StepMotor(2);
	EXPECT_EQ(sm.timeout, 10);
	sm.set_speed(1);
	EXPECT_EQ(sm.timeout, 1);
	}

TEST(stepmotor, resetimer) {
	StepMotor sm = StepMotor(2);
	unsigned long tmp = sm.update_time;
	EXPECT_EQ(sm.update_time, tmp);
	sm.resetimer();
	EXPECT_NE(sm.update_time, tmp);
	}

TEST(stepmotor, runtime) {
	StepMotor sm = StepMotor(2);
	unsigned long tmp = sm.update_time;
	sm.move(10);
	EXPECT_EQ(sm.value, 10);
	EXPECT_EQ(sm.update_time, tmp);
	sm.runtime();
	EXPECT_EQ(sm.update_time, tmp);
	EXPECT_EQ(sm.value, 10);
	delay(100);
	sm.runtime();
	EXPECT_NE(sm.update_time, tmp);
	EXPECT_EQ(sm.value, 9);
	sm.set_speed(0);
	sm.resetimer();
	tmp = sm.update_time;
	EXPECT_EQ(sm.update_time, tmp);
	EXPECT_EQ(sm.value, 9);
	sm.runtime();
	EXPECT_NE(sm.update_time, tmp);
	EXPECT_EQ(sm.value, 8);
	}

TEST(stepmotor, Stop) {
	StepMotor sm = StepMotor(2);
	sm.move(10);
	EXPECT_EQ(sm.value, 10);
	sm.step();
	EXPECT_EQ(sm.value, 9);
	sm.stop(100);
	EXPECT_EQ(sm.value, 100);
	sm.stop();
	EXPECT_EQ(sm.value, 0);
	sm.step();
	EXPECT_EQ(sm.value, 0);
	sm.step();
	EXPECT_EQ(sm.value, 0);
	}

#endif
