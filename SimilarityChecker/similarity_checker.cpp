#include <string>
#include <algorithm>
using std::string;

class SimilarityChecker {
public:
	int calScore(const string& left, const string& right) {
		if (left.length() > right.length()) {
			return calScoreWithLength(left, right);
		}
		else {
			return calScoreWithLength(right, left);
		}
	}
	int calScoreWithLength(const std::string& lagerString, const std::string& smallerString)
	{
		double gap = lagerString.length() - smallerString.length();
		double scoreTypeDouble = (ONE - (gap / smallerString.length())) * MAX_LENGTH_SCORE;

		return floor(scoreTypeDouble);
	}

	int calScoreWithAlpha(const std::string& left, const std::string& right) {
		string concatString = left + right;
		int TotalCnt = 0;
		int SameCnt = 0;
		for (char alpha = 'A'; alpha <= 'Z'; ++alpha) {
			for (char c : concatString) {
				if (alpha == c) {
					TotalCnt++;
					break;
				}
			}
		}
		string leftTemp = left;
		leftTemp.erase(std::unique(leftTemp.begin(), leftTemp.end()), leftTemp.end());
		string rightTemp = right;
		rightTemp.erase(std::unique(rightTemp.begin(), rightTemp.end()), rightTemp.end());

		for (char l : leftTemp) {
			for (char r : rightTemp) {
				if (l  == r) {
					SameCnt++;
				}
			}
		}
		return floor(((double)SameCnt / TotalCnt) * 40);
	}
private:
	constexpr static double ONE = 1.f;
	constexpr static double MAX_LENGTH_SCORE = 60.f;
};