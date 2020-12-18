#include "../include.h"

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ret;
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        for (int i = 0; i < row_size; ++i) {
            int min = INT_MAX;
            int min_idx = -1;
            for (int j = 0; j < col_size; ++j) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    min_idx = j;
                }
            }
            int max = INT_MIN;
            for (int k = 0; k < row_size; ++k) {
                if (matrix[k][min_idx] > max) {
                    max = matrix[k][min_idx];
                }
            }
            if (max == min) {
                ret.push_back(min);
            }
        } // for
        return ret;
    }
};

void test1() {
    vector<vector<int>> mat {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> ret {15};
    Solution soln;
    assert(isArrayEqual(soln.luckyNumbers(mat), ret));
}

void test2() {
    vector<vector<int>> mat {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    vector<int> ret {12};
    Solution soln;
    assert(isArrayEqual(soln.luckyNumbers(mat), ret));
}

void test3() {
    vector<vector<int>> mat {{7,8},{1,2}};
    vector<int> ret {7};
    Solution soln;
    assert(isArrayEqual(soln.luckyNumbers(mat), ret));
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
