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
		string leftUnique = getUniqueCharString(left);
		string rightUnique = getUniqueCharString(right);;

		int totalCnt = getTotalCount(leftUnique, rightUnique);
		int sameCnt = getSameCount(leftUnique, rightUnique);

		return calAlphaScore(totalCnt, sameCnt);
	}
private:
	constexpr static double ONE = 1.f;
	constexpr static double MAX_LENGTH_SCORE = 60.f;
	constexpr static double MAX_ALPHA_SCORE = 40.f;

	string getUniqueCharString(const string& original) {
		string temp = original;
		temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
		
		return temp;
	}
	int calAlphaScore(int totalCnt, int sameCnt) {
		return floor(((double)sameCnt / totalCnt) * MAX_ALPHA_SCORE);
	}
	int getTotalCount(const string& left, const string& right) {
		string concatStr = left + right;
		string uniqueConcatStr = getUniqueCharString(concatStr);

		return uniqueConcatStr.length();
	}
	int getSameCount(const string& left, const string& right) {
		int cnt = 0;

		for (char l : left) {
			for (char r : right) {
				if (l == r) {
					cnt++;
					break;
				}
			}
		}

		return cnt;
	}
};