#include "../include.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            swap(s[i], s[n-i-1]);
        }
    }
};

void test() {
    vector<char> s1 {'h','e','l','l','o'};
    vector<char> s2 {'H','a','n','n','a','h'};
    vector<char> inv1 {'o','l','l','e','h'};
    vector<char> inv2 {'h','a','n','n','a','H'};
    Solution soln;
    soln.reverseString(s1);
    soln.reverseString(s2);
    assert(s1 == inv1);
    assert(s2 == inv2);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
