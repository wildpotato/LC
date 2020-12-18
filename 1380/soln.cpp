#include "../include.h"

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ret;
        int row_size = matrix.size();
        if (row_size == 0) {
            return ret;
        }
        int col_size = matrix.size();
        vector<int> row_min_idx;
        vector<int> col_max_idx;
        for (int i = 0; i < row_size; ++i) {
            int min_in_row = matrix[i][0];
            int min_idx = 0;
            for (int j = 0; j < col_size; ++j) {
                if (matrix[i][j] < min_in_row) {
                    min_in_row = matrix[i][j];
                    min_idx = j;
                } // if
            } // for
            row_min_idx.push_back(min_idx);
        } // for

        for (int j = 0; j < col_size; ++j) {
            int max_in_col = matrix[0][j];
            int max_idx = 0;
            for (int i = 0; i < row_size; ++i) {
                if (matrix[i][j] > max_in_col) {
                    max_in_col = matrix[i][j];
                    max_idx = i;
                } // if
            } // for
            col_max_idx.push_back(max_idx);
        } // for

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
