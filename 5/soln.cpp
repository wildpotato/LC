#include "../include.h"

class Solution {
public:
    string longestPalindrome(string s) {
		if (s.length() < 2) {
			return s;
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); ++i) {
			int len1 = expandFromCenter(s, i, i);
			int len2 = expandFromCenter(s, i, i+1);
			int len = max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
    }

	int expandFromCenter(string s, int left, int right) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			left--;
			right++;
		}
		return right - left - 1;
	}
};

void test() {
	Solution soln;
	string ans1 = soln.longestPalindrome("babad");
	assert(ans1 == "bab" || ans1 == "aba");
	assert(soln.longestPalindrome("cbbd") == "bb");
	assert(soln.longestPalindrome("a") == "a");
	string ans2 = soln.longestPalindrome("ac");
	assert(ans2 == "a" || ans2 == "c");
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
