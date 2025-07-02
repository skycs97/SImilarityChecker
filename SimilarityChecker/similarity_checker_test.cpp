#include "gmock/gmock.h"
#include "similarity_checker.cpp"
#include <iostream>
#include <cstdio>

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker checker;

	void scoreChecker(int expected, const string& left, const string& right) {
		int actual = checker.calScore(left, right);

		EXPECT_EQ(expected, actual);
	}
	void scoreCheckerOnlyAlpha(int expected, const string& left, const string& right) {
		int actual = checker.calScoreWithAlpha(left, right);

		EXPECT_EQ(expected, actual);
	}
};

TEST_F(SimilarityCheckerFixture, LengthScore60) {
	int expected = 60;
	scoreChecker(expected, "AAA", "BBB");
}

TEST_F(SimilarityCheckerFixture, LengthScore0) {
	int expected = 0;
	scoreChecker(expected, "AA", "B");
}

TEST_F(SimilarityCheckerFixture, LengthScore20) {
	int expected = 20;
	scoreChecker(expected, "AAABB", "BAA");
}

TEST_F(SimilarityCheckerFixture, LengthScore30) {
	int expected = 30;
	scoreChecker(expected, "AA", "AAE");
}

TEST_F(SimilarityCheckerFixture, alphaScore40NoSame) {
	int expected = 40;
	scoreCheckerOnlyAlpha(expected, "ABCD", "DBCA");
}
TEST_F(SimilarityCheckerFixture, alphaScore0NoSame) {
	int expected = 0;
	scoreCheckerOnlyAlpha(expected, "AB","CD");
}
TEST_F(SimilarityCheckerFixture, alphaScore0WithSame) {
	int expected = 20;
	scoreCheckerOnlyAlpha(expected, "AA", "AAE");
}
TEST_F(SimilarityCheckerFixture, alphaScore40WithSame) {
	int expected = 40;
	scoreCheckerOnlyAlpha(expected, "AAABB", "BA");
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}