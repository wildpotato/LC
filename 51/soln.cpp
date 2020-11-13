#include "../include.h"

class Solution {

    public:
        bool promising(int row, int col) {
            return column[col] == AVAILABLE
                && leftDiagonal[row + col] == AVAILABLE
                && rightDiagonal[row - col + (n - 1)] == AVAILABLE;
        } // promising

        vector<vector<string>> solveNQueens(int n) {
            this->n = n;
            positionInRow.resize(n, 0);
            column.resize(n, AVAILABLE);
            leftDiagonal.resize(2*n - 1, AVAILABLE);
            rightDiagonal.resize(2*n - 1, AVAILABLE);
            putQueen(0);
            return ret;
        }

        void putQueen(int row) {
            // Check for solution
            if (row == n) {
                ret.push_back(getSolution());
                //print1DArray(positionInRow);
                return;
            }
            for (int col = 0; col < n; ++col) {
                if (promising(row, col)) {
                    // Make the move, and a recursive call to next move
                    positionInRow[row] = col;
                    column[col] = NOT_AVAIL;
                    leftDiagonal[row + col] = NOT_AVAIL;
                    rightDiagonal[row - col + (n - 1)] = NOT_AVAIL;
                    putQueen(row + 1);
                    // Undo this move and thus backtrack
                    column[col] = AVAILABLE;
                    leftDiagonal[row + col] = AVAILABLE;
                    rightDiagonal[row - col + (n - 1)] = AVAILABLE;
                } // if
            } // for
        } // putQueen

        vector<string> getSolution() {
            vector<string> soln(n, "");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (positionInRow[i] == j) {
                        soln[i].append("Q");
                    } else {
                       soln[i].append(".");
                    }
                }
            }
           return soln;
        }
        void print1DArray(const vector<int> &vec) {
            cout << "----------\n";
            for (int i = 0; i < vec.size(); ++i) {
                cout << vec[i] << "\n";
            }
            cout << "----------\n";
        }

        void print1DArray(const vector<bool> &vec) {
            cout << "----------\n";
            for (int i = 0; i < vec.size(); ++i) {
                if (vec[i] == AVAILABLE) {
                    cout << "T\n";
                } else {
                    cout << "F\n";
                }
            }
            cout << "----------\n";
        }

        void printResult(const vector<vector<string>> &ret) {
            for (int i = 0; i < ret.size(); ++i) {
                cout << "Solution " << i+1 << ":\n";
                for (int j = 0; j < ret[0].size(); ++j) {
                    cout << "\"" << ret[i][j] << "\"\n";
                }
            }
        }

        int n; // dimension of board
        vector<vector<string>> ret;
        vector<int> positionInRow;
        vector<bool> column;
        vector<bool> leftDiagonal;
        vector<bool> rightDiagonal;
    private:
        const bool AVAILABLE = true;
        const bool NOT_AVAIL = false;
};

int main() {
    vector<vector<string>> ret;
    Solution soln;
    ret = soln.solveNQueens(4);
    soln.printResult(ret);
    return 0;
}
