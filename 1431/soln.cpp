#include "../include.h" // isArrayEqual()

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int size = candies.size();
        vector<bool> ret; // do not allocate mem may be faster here
        int max_candy = candies[0];
        for (int i = 1; i < size; i++) {
            if (candies[i] > max_candy) {
                max_candy = candies[i];
            }
        }
        for (int i = 0; i < size; ++i) {
            ret.push_back(candies[i] + extraCandies >= max_candy);
        }
        return ret;
    }
};

void test1() {
    Solution soln;
    vector<int> candies {2,3,5,1,3};
    vector<bool> golden {true, true, true, false, true};
    vector<bool> ret (candies.size(), false);
    ret = soln.kidsWithCandies(candies,3);
    assert(isArrayEqual(ret, golden));
}

void test2() {
    Solution soln;
    vector<int> candies {4,2,1,1,2};
    vector<bool> golden {true, false, false, false, false};
    vector<bool> ret (candies.size(), false);
    ret = soln.kidsWithCandies(candies,1);
    assert(isArrayEqual(ret, golden));
}

void test3() {
    Solution soln;
    vector<int> candies {12,1,12};
    vector<bool> golden {true, false, true};
    vector<bool> ret (candies.size(), false);
    ret = soln.kidsWithCandies(candies,10);
    assert(isArrayEqual(ret, golden));
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
