#include "../include.h"

class Solution {
public:
    int reverse(int x) {
        long ret = 0;
        while (x != 0) {
            ret *= 10;
            ret += (x % 10);
            x /= 10;
        }
        if (x < 0) {
            ret *= -1;
        }
        if (ret > INT_MAX || ret < INT_MIN) {
            ret = 0;
        }
        return (int)ret;
    }
};

void test() {
    Solution soln;
    assert(soln.reverse(123) == 321);
    assert(soln.reverse(-123) == -321);
    assert(soln.reverse(120) == 21);
    assert(soln.reverse(0) == 0);
}

int main() {
    test();
    cout << "Successful\n";
}
