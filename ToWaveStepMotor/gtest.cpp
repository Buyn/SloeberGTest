#ifdef UNITTEST
#include "gtest.h"
#include "towavestepmotor.h"
#include "blink.h"
#include "defcfg.h"


TEST(main, init) {
	Blink t = Blink();
	t.test_setup();
	int temtest = t.sm.get_longs();
	EXPECT_EQ(DEBAG_STEP_LONGS, 2000);
	// а эти не работают
//	EXPECT_EQ(temtest,2000);
//	EXPECT_EQ(t.sm.get_longs(),2000);
//	EXPECT_EQ(t.sm.get_timeout(),2000);
	}

TEST(main, loop) {
	Blink t = Blink();
	t.test_setup();
	EXPECT_EQ(t.sm.get_longs(), 500);
	EXPECT_EQ(t.sm.get_timeout(), 500);
	t.test_loop();
	EXPECT_EQ(t.sm.get_movesleft(), 500);
	while(t.sm.get_movesleft() >= 5){
		t.test_loop();
//		delay(1);
		}
	EXPECT_EQ(t.sm.get_movesleft(), 4);
	// а эти не работают
//	EXPECT_EQ(temtest,2000);
//	EXPECT_EQ(t.sm.get_longs(),2000);
//	EXPECT_EQ(t.sm.get_timeout(),2000);
	}

TEST(stepmotor, init) {
	ToWaveStepMotor sm = ToWaveStepMotor(2);
	EXPECT_EQ(sm.pin,2);
	EXPECT_EQ(sm.value,0);
	}
TEST(stepmotor, Step) {
	ToWaveStepMotor sm = ToWaveStepMotor(2);
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
	ToWaveStepMotor sm = ToWaveStepMotor(2);
//	EXPECT_EQ(sm.timeout, START_TIME_OUT);
	sm.set_speed(1);
	EXPECT_EQ(sm.timeout, 1);
	}

TEST(stepmotor, resetimer) {
	ToWaveStepMotor sm = ToWaveStepMotor(2);
	unsigned long tmp = sm.update_time;
	EXPECT_EQ(sm.update_time, tmp);
	sm.resetimer();
	EXPECT_NE(sm.update_time, tmp);
	}

TEST(stepmotor, runtime) {
	ToWaveStepMotor sm = ToWaveStepMotor(2);
	sm.set_timeout(2);
	sm.set_longs(2);
	unsigned long tmp = sm.update_time;
	sm.move(10);
	EXPECT_EQ(sm.value, 10);
	EXPECT_EQ(sm.update_time, tmp);
	EXPECT_EQ(sm.enable, false);
	sm.runtime();
	EXPECT_EQ(sm.enable, false);
	EXPECT_EQ(sm.update_time, tmp);
	EXPECT_EQ(sm.value, 10);
	delay(1);
	sm.runtime();
	EXPECT_EQ(sm.enable, true);
	EXPECT_NE(sm.update_time, tmp)<<" "<<micros();
	delay(1);
	EXPECT_EQ(sm.value, 9)<<" "<<micros();
	delay(1);
	sm.set_speed(0);
	sm.set_timeout(0);
	sm.set_longs(0);
	sm.resetimer();
	tmp = sm.update_time;
	EXPECT_EQ(sm.update_time, tmp)<<" "<<micros();
	EXPECT_EQ(sm.value, 9)<<" "<<micros();
	sm.runtime();
	EXPECT_EQ(sm.enable, false);
	EXPECT_NE(sm.update_time, tmp);
	EXPECT_EQ(sm.value, 9);
	}

TEST(stepmotor, Done) {
	ToWaveStepMotor sm = ToWaveStepMotor(2);
	sm.set_speed(2);
	sm.move(3);
	EXPECT_EQ(sm.value, 3);
	sm.step();
	sm.step();
	EXPECT_FALSE(sm.done());
	EXPECT_EQ(sm.value, 1);
	sm.step();
	EXPECT_EQ(sm.value, 0);
	EXPECT_TRUE(sm.done());
	EXPECT_EQ(sm.value, 0);
	EXPECT_FALSE(sm.done());
	EXPECT_EQ(sm.value, 0);
	sm.move(1);
	EXPECT_EQ(sm.value, 1);
	EXPECT_FALSE(sm.done());
	sm.step();
	EXPECT_EQ(sm.value, 0);
	EXPECT_TRUE(sm.done());
	EXPECT_EQ(sm.value, 0);
	EXPECT_FALSE(sm.done());
	EXPECT_EQ(sm.value, 0);
//	EXPECT_NE(sm.update_time, tmp)<<" "<<micros();
	}

TEST(stepmotor, Stop) {
	ToWaveStepMotor sm = ToWaveStepMotor(2);
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
