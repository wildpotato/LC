#include "../include.h"

class Solution {
public:
    inline int northEdge(vector<vector<int>> &grid, int row_pos, int col_pos) {
        if (row_pos == 0) {
            return 1;
        }
        return grid[row_pos - 1][col_pos] == 0 ? 1 : 0;
    }

    inline int eastEdge(vector<vector<int>> &grid, int row_pos, int col_pos, int col_size) {
        if (col_pos == col_size - 1) {
            return 1;
        }
        return grid[row_pos][col_pos + 1] == 0 ? 1 : 0;
    }

    inline int southEdge(vector<vector<int>> &grid, int row_pos, int col_pos, int row_size) {
        if (row_pos == row_size - 1) {
            return 1;
        }
        return grid[row_pos + 1][col_pos] == 0 ? 1 : 0;
    }

    inline int westEdge(vector<vector<int>> &grid, int row_pos, int col_pos) {
        if (col_pos == 0) {
            return 1;
        }
        return grid[row_pos][col_pos - 1] == 0 ? 1 : 0;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0, row_size = grid.size(), col_size = grid[0].size();
        for (int row = 0; row < row_size; ++row) {
            for (int col = 0; col < col_size; ++col) {
                if (grid[row][col] == 1) {
                    perimeter += northEdge(grid, row, col) + \
                                 eastEdge(grid, row, col, col_size) + \
                                 southEdge(grid, row, col, row_size) + \
                                 westEdge(grid,row, col);
                }
            }
        }
        return perimeter;
    }
};

void test1() {
    vector<vector<int>> grid {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution soln;
    assert(soln.islandPerimeter(grid) == 16);
}

void test2() {
    vector<vector<int>> grid {{1}};
    Solution soln;
    assert(soln.islandPerimeter(grid) == 4);
}

void test3() {
    vector<vector<int>> grid {{1,0}};
    Solution soln;
    assert(soln.islandPerimeter(grid) == 4);
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
