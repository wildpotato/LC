#include "../include.h"

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> occurrence(26, 0);
        for (char c : s) {
            occurrence[c - 'a'] += 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (occurrence[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

void test() {
    string s1 = "leetcode";
    string s2 = "loveleetcode";
    Solution soln;
    assert(soln.firstUniqChar(s1) == 0);
    assert(soln.firstUniqChar(s2) == 2);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
