#include "../include.h"

class Solution {
public:
    bool isPalindrome(string s) {
		int s_len = s.length();
		if (s_len < 2) {
			return true;
		}
		stack<char> stk;
		for (const char c : s) {
			if (isalnum(c)) {
				stk.push((char)tolower(c));
			}
		}
		for (const char c : s) {
			if (isalnum(c)) {
				if (stk.top() != (char)tolower(c)) {
					return false;
				}
				stk.pop();
			}
		}
		return stk.empty();
    }
};

void test() {
	Solution soln;
	assert(soln.isPalindrome("A man, a plan, a canal: Panama"));
	assert(!soln.isPalindrome("race a car"));
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
