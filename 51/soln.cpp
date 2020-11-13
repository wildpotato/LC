#include "../include.h"

class Solution {
    public:
        //bool promising(unsigned int row, unsigned int col) {
        //    return column[col] == AVAILABLE
        //        && leftDiagonal[row + col] == AVAILABLE
        //        && rightDiagonal[row - col + (n - 1)] == AVAILABLE;
        //} // promising

        vector<vector<string>> solveNQueens(int n) {
            this->n = n;
            vector<string> s1;
            for (int i = 0; i < n; ++i) {
                string row(n, '.');
                s1.push_back(row);
            }
            ret.push_back(s1);
            return ret;
        }

        void printResult(const vector<vector<string>> &ret) {
            for (int i = 0; i < ret.size(); ++i) {
                for (int j = 0; j < ret[0].size(); ++j) {
                    cout << "\"" << ret[i][j] << "\"\n";
                }
            }
        }

        int n; // dimension of board
        vector<vector<string>> ret;
};

int main() {
    vector<vector<string>> ret;
    Solution soln;
    ret = soln.solveNQueens(4);
    soln.printResult(ret);
    return 0;
}
