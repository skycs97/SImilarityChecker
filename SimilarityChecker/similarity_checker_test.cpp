#include "gmock/gmock.h"
#include "similarity_checker.cpp"
#include <iostream>
#include <cstdio>

TEST(SimilarityCheckerTest, LengthScore60) {
	SimilarityChecker checker;

	string a = "AAA";
	string b = "BBB";
	
	int expected = 60;
	int actual = checker.calScore(a, b);
	EXPECT_EQ(expected, actual);
}

TEST(SimilarityCheckerTest, LengthScore0) {
	SimilarityChecker checker;

	string a = "A";
	string b = "BB";

	int expected = 0;
	int actual = checker.calScore(a, b);
	EXPECT_EQ(expected, actual);
}

TEST(SimilarityCheckerTest, LengthScore20) {
	SimilarityChecker checker;

	string a = "AAABB";
	string b = "BAA";

	int expected = 20;
	int actual = checker.calScore(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityCheckerTest, LengthScore30) {
	SimilarityChecker checker;

	string a = "AA";
	string b = "AAE";

	int expected = 30;
	int actual = checker.calScore(a, b);
	EXPECT_EQ(expected, actual);
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}