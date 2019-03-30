#ifdef UNITTEST

#include "gtest.h"
#include "Stack.h"

TEST(Stack, start) {
	Stack <int> stack;
	stack.push(10);
//	EXPECT_EQ(stack.push(10), NULL);
	EXPECT_EQ(10, stack.peek());
	EXPECT_NE(1, stack.peek());
	//EXPECT_EQ(1, stack.size());
	EXPECT_EQ(10, stack.pop());
	//EXPECT_EQ(10, stack.pop());
	}

TEST(Stack, startMult) {
	Stack <int> stackM(10);
	stackM.push(10);
	EXPECT_EQ(1, stackM.count());
	EXPECT_EQ(10, stackM.peek());
//	EXPECT_NE(1, stack.peek());
	stackM.push(22);
	EXPECT_NE(1, stackM.peek());
//	EXPECT_EQ(22, stack.pop());
//	EXPECT_EQ(10, stackM.peek());
	}

TEST(Stack, exComands) {
	Stack <int> stackE(10);
	stackE.pushEx(10);
	EXPECT_NE(1, stackE.peekEx());
//	stackM.push(22);
//	EXPECT_NE(1, stack.peek());
	EXPECT_EQ(10, stackE.popEx());
//	EXPECT_EQ(10, stackM.peek());
	}
TEST(Stack, belowStakPop) {
	Stack <int> stackE(2);
	stackE.push(10);
	stackE.push(20);
	EXPECT_EQ(20, stackE.pop());
	EXPECT_EQ(10, stackE.pop());
	EXPECT_EQ(20, stackE.pop());
	}
TEST(Stack, belowStakPeek) {
	Stack <int> stackE(2);
	stackE.push(10);
	stackE.push(20);
	EXPECT_EQ(20, stackE.pop());
	EXPECT_EQ(10, stackE.pop());
	EXPECT_EQ(20, stackE.peek());
	}
TEST(Stack, aboveStakPush) {
	Stack <int> stackE(2);
	stackE.push(10);
	stackE.push(20);
	EXPECT_EQ(20, stackE.peek());
	stackE.push(30);
	EXPECT_EQ(30, stackE.peek());
	EXPECT_EQ(30, stackE.pop());
	EXPECT_EQ(20, stackE.pop());
	EXPECT_EQ(30, stackE.pop());
	EXPECT_EQ(20, stackE.peek());
	}
#endif
