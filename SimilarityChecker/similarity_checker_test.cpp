#include "gmock/gmock.h"
#include "similarity_checker.cpp"

TEST(TS, TC1) {
	EXPECT_EQ(1, 1);
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}