#include "../include.h"

class Solution {
public:
    int numberOfSteps (int num) {

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
