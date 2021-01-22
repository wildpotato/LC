#include "../include.h"

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) return true;
        for (int beg = 0, end = s.size() - 1; beg <= end; ++beg, --end) {
            // upon discrepancy, leave out character at either side and check if
            // it is a valid palindrome with just single character deleted.
            if (s[beg] != s[end]) {
                // will fail if pass in ++beg and --end, use +-1 instead
                return isValidPalindrome(s, beg+1, end) || isValidPalindrome(s, beg, end-1);
            }
        }
        return true;
    }

    // helper method to check if a given string is a valid palindrome with
    // starting pointer beg and ending pointer end.
    bool isValidPalindrome(string s, int beg, int end) {
        while (beg <= end) {
            if (s[beg] != s[end]) {
                return false;
            }
            ++beg;
            --end;
        }
        return true;
    }
};

void test() {
    string s1 = "aba";
    string s2 = "abca";
    string s3 = "abcda";
    Solution soln;
    assert(soln.validPalindrome(s1));
    assert(soln.validPalindrome(s2));
    assert(!soln.validPalindrome(s3));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
