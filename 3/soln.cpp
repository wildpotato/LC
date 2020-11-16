#include "../include.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

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

void test3 {
    string s = "pwwkew";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 3);
}

void test4 {
    string s = "";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 0);
}

int main() {
    test1;
    test2;
    test3;
    test4;
    return 0;
}
