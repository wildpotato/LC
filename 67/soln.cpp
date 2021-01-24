#include "../include.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
            if (i >= 0) carry += a[i] - '0';
            if (j >= 0) carry += b[j] - '0';
            ret = to_string(carry & 1) + ret;
            carry = carry >> 1;
        }
        return carry ? "1" + ret : ret;
    }
};

void test() {
    Solution soln;
    assert(soln.addBinary("1010", "1011") == "10101");
    assert(soln.addBinary("11", "1") == "100");
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
