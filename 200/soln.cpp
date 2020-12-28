#include "../include.h"

class Solution {
public:
	int count = 0;
	int rows = 0;
	int cols = 0;
    int numIslands(vector<vector<char>>& grid) {
		rows = grid.size();
		cols = grid[0].size();
		vector<vector<bool> > visited(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					explore(i, j, grid, visited);
					count++;
				}
			}
		}
		return count;
	}
	void explore(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
		if (i < 0 || j < 0 || i >= rows || j >= cols) {
			return;
		}
		if (grid[i][j] == '0' || visited[i][j]) {
			return;
		}
		visited[i][j] = true;
		explore(i, j-1, grid, visited);
		explore(i, j+1, grid, visited);
		explore(i-1, j, grid, visited);
		explore(i+1, j, grid, visited);
	}
};
void test1() {
	vector<vector<char>> grid {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	Solution soln;
	assert(soln.numIslands(grid) == 1);
}

void test2() {
	vector<vector<char>> grid {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};
	Solution soln;
	assert(soln.numIslands(grid) == 3);
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
