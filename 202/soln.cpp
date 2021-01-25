#include "../include.h"

/*
 *  We first try a couple examples and think about the problem.
 *
 *  Example 1: n = 19
 *  19 -> 82 -> 68 -> 100 -> 1 (happy)
 *
 *  Example 2: n = 2
 *  2 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 (infinite loop, unhappy)
 *
 *  For all the possible numbers, there are likely three scanerios:
 *  1. The number eventually goes down to 1
 *  2. The number enters an infinite loop
 *  3. The number keeps growing
 *
 *  However, looking at the below table, we know we can rule out the
 *  third scanerio.
 *
 *    Number      Next number
 *        9               81
 *      999              243
 *      ...              ...
 *  9999999999999       1053
 *
 *  Thus, all we need to do is handle the infinite loop, we can easily
 *  achieve this by using a hash table with O(1) lookup.
 *
 */

class Solution {
public:
    bool isHappy(int n) {
        set<int> table;
        while (n != 1) {
            auto itr = table.find(n);
            if (itr != table.end()) {
                return false;
            } else {
                table.insert(n);
            }
            n = getNext(n);
        }
        return true;
    }

    int getNext(int n) {
        int next = 0;
        while (n) {
            next += pow(n % 10, 2);
            n /= 10;
        }
        return next;
    }
};

void test() {
    Solution soln;
    assert(soln.isHappy(19));
    assert(!soln.isHappy(2));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
