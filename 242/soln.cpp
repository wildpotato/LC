#include "../include.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        constexpr int SIZE = 26;
        vector<int> count(SIZE, 0);
        for (const char ch : s) {
            count[ch - 'a']++;
        }
        for (const char ch: t) {
            count[ch - 'a']--;
        }
        for (const int cnt: count) {
            if (cnt != 0) {
                return false;
            }
        }
        return true;
    }
};

void test1() {
    string s = "anagram";
    string t = "nagaram";
    Solution soln;
    assert(soln.isAnagram(s, t));
}


void test2() {
    string s = "rat";
    string t = "car";
    Solution soln;
    assert(!soln.isAnagram(s, t));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
