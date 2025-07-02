#include <string>

using std::string;

class SimilarityChecker {
public:
	int  checkLength(const string& a, const string& b) {
		if (a.length() == b.length()) {
			return 60.;
		}

		double gap = 0;
		if (a.length() > b.length()) {
			gap = a.length() - b.length();
		}
		else {
			gap = b.length() - a.length();
		}

		if (a.length() > b.length()) {
			return floor((1.f - (gap / b.length())) * 60);
		}
		else {
			return floor((1.f - (gap / a.length())) * 60);
		}
	}
};