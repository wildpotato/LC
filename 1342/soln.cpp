#include "../include.h"

class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        if (num == 0) {
            return count;
        }
        while (num != 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            count++;
        }
        return count;
    }
};

void test1() {
    Solution soln;
    assert(soln.numberOfSteps(14) == 6);
}

void test2() {
    Solution soln;
    assert(soln.numberOfSteps(8) == 4);
}

void test3() {
    Solution soln;
    assert(soln.numberOfSteps(123) == 12);
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
