#include <string>

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
private:
	constexpr static double ONE = 1.f;
	constexpr static double MAX_LENGTH_SCORE = 60.f;
};