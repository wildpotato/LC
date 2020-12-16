#include "../include.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};

void test() {
    uint32_t n1 = 0b00000000000000000000000000001011;
    uint32_t n2 = 0b00000000000000000000000010000000;
    uint32_t n3 = 0b11111111111111111111111111111101;
    Solution soln;
    assert(soln.hammingWeight(n1) == 3);
    assert(soln.hammingWeight(n2) == 1);
    assert(soln.hammingWeight(n3) == 31);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
