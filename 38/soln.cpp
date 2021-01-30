#include "../include.h"
/*
 * Here is the pattern of count and say:
 * n = 1:       1
 * n = 2:       1 1
 * n = 3:       2 1
 * n = 4:       1 2 1 1
 * n = 5:       1 1 1 2 2 1
 * n = 6:       3 1 2 2 1 1
 * n = 7:       1 3 1 1 2 2 2 1
 *
 * We are going to loop n times to find the final result, while during each
 * iteration we need two additional variables. The first variable loops thru
 * the string obtained from the previous iteration and the second variable
 * counts the number of contiguous numbers in each chunk.
 *
 */
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string ns;
            int i = 0;
            while (i < s.size()) {
                int count = 1;
                while (i + 1 < s.size() && s[i] == s[i+1]) {
                    count++;
                    i++;
                }
                ns += to_string(count) + s[i];
                i++;
            }
            s = ns;
        }
        return s;
    }
};

void test() {
    Solution soln;
    assert(soln.countAndSay(1) == "1");
    assert(soln.countAndSay(2) == "11");
    assert(soln.countAndSay(3) == "21");
    assert(soln.countAndSay(4) == "1211");
    assert(soln.countAndSay(5) == "111221");
    assert(soln.countAndSay(6) == "312211");
    assert(soln.countAndSay(7) == "13112221");
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
