#include "../include.h"

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n > 26) {
            ret += toTitle((n-1) / 26);
            n %= 26;
        }
        if (n < 26) {
            ret += toTitle(n);
        }
        return ret;
    }

    char toTitle(int n) {
        return char(int('A') + n - 1);
    }
};

void test() {
    Solution soln;
    string ret1 = soln.convertToTitle(1);
    string ret2 = soln.convertToTitle(28);
    string ret3 = soln.convertToTitle(701);
    string ret4 = soln.convertToTitle(26);
    assert(ret1 == "A");
    assert(ret2 == "AB");
    assert(ret3 == "ZY");
    assert(ret4 == "Z");
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
