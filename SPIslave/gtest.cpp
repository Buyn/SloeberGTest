#ifdef UNITTEST

#include "gtest.h"
#include "Stack.h"
//#include "slavespi.h"

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


#endif
