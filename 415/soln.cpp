#include "../include.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret = "";
        int carry = 0;
        for (int i1 = num1.length() - 1, i2 = num2.length() - 1;
                i1 >= 0 || i2 >= 0; --i1, --i2) {
            int tmp = 0;
            if (i1 >= 0 && i2 >= 0) {
                tmp = (num1[i1] - '0') + (num2[i2] - '0') + carry;
            } else {
                if (i1 >= 0) {
                    tmp = (num1[i1] - '0') + carry;
                } else {
                    tmp = (num2[i2] - '0') + carry;
                }
            }
            if (tmp > 9) {
                carry = 1;
                tmp -= 10;
            } else {
                carry = 0;
            }
            ret.insert(0, to_string(tmp));
        }
        if (carry == 1) {
            ret.insert(0, "1");
        }
        return ret;
    }
};

void test1() {
    Solution soln;
    string ret = "0";
    assert(soln.addStrings("0", "0") == ret);
}


void test2() {
    Solution soln;
    string ret = "1998";
    assert(soln.addStrings("999", "999") == ret);
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
