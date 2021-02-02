#include "../include.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i+1,0);
            if (i == 0) ret[0] = {1};
            if (i == 1) ret[1] = {1, 1};
        }
        for (int i = 2; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 or j == i) {
                    ret[i][j] = 1;
                } else {
                    ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
                }
            }
        }
        return ret;
    }
};

void test() {
    vector<vector<int>> ret{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
    Solution soln;
    assert(isArrayEqual(ret, soln.generate(5)));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
