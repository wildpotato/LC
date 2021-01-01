#include "../include.h"

class Solution {
public:
    string longestPalindrome(string s) {

    }
};

void test() {
	Solution soln;
	string ans1 = soln.longestPalindrome("babad");
	assert(ans1 == "bab" || ans1 == "aba");
	assert(soln.longestPalindrome("cbbd") == "bb");
	assert(soln.longestPalindrome("a") == "a");
	assert(soln.longestPalindrome("ac") == "a");
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
