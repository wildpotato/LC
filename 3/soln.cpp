#include "../include.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int bestSoFar = 0;
		for (unsigned int i = 0; i < s.length()-1; ++i) {
			int soFar = 0;
			for (unsigned int j = i + 1; j < s.length(); ++j) {
				if (s.substr(i, j-i).find(s[j]) != string::npos) {
					break;
				}
				else {
					soFar++;
					if (soFar > bestSoFar) {
						bestSoFar = soFar;
					}
				}
			}
		}
		cout << "bestSoFar=" << bestSoFar << "\n";
		return bestSoFar;
    }

};

void test1() {
    string s = "abcabcbb";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 3);
}

void test2() {
    string s = "bbbbb";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 1);
}

void test3() {
    string s = "pwwkew";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 3);
}

void test4() {
    string s = "";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 0);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
