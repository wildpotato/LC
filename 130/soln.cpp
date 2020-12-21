#include "../include.h"

class Solution {
public:
	/* when an island (of O's) contains any 'O' on the boarder, this global var
	 * exposed becomes true to indicate this island is "exposed" and should not
	 * be changed to X's.
	 */
	bool exposed = false;
	int num_of_rows = 0;
	int num_of_cols = 0;
    void solve(vector<vector<char>>& board) {
		num_of_rows = board.size();
		if (num_of_rows <= 2) {
			return;
		}
		num_of_cols = board[0].size();
		if (num_of_cols <= 2) {
			return;
		}
		vector<vector<bool>> visited(num_of_rows, vector<bool>(num_of_cols, false));
		for (int i = 1; i < num_of_rows - 1; ++i) {
			for (int j = 1; j < num_of_cols - 1; ++j) {
				if (board[i][j] == 'O' && !visited[i][j]) {
					exposed = false;
					visitDFS(board, i, j, visited);
					if (!exposed) {
						markDFS(board, i, j);
					}
				} // if cell is unvisited 'O'
			} // inner for
		} // outer for
    }
private:
	void visitDFS(vector<vector<char>> &board, int r, int c, vector<vector<bool>> &visited) {
		if (r < 0 || r >= num_of_rows || c < 0 || c >= num_of_cols) {
			return;
		} // definitely out of bounds
		if (board[r][c] == 'X' || visited[r][c]) {
			return;
		} // return on 'X' or already visited
		if (r == 0 || r == num_of_rows-1 || c == 0 || c == num_of_cols-1) {
			exposed = true;
		} // cell is boarder 'O' (exposed!)
		visited[r][c] = true;
		visitDFS(board, r, c-1, visited); // explore west cell
		visitDFS(board, r, c+1, visited); // explore east cell
		visitDFS(board, r-1, c, visited); // explore north cell
		visitDFS(board, r+1, c, visited); // explore south cell
	} // visitDFS
	void markDFS(vector<vector<char>> &board, int r, int c) {
		if (r < 0 || r >= num_of_rows || c < 0 || c >= num_of_cols) {
			return;
		} // definitely out of bounds
		if (board[r][c] == 'X') {
			return;
		} // return on 'X'
		board[r][c] = 'X'; // mark encircled 'O' as 'X'
		markDFS(board, r-1, c); // mark north cell
		markDFS(board, r+1, c); // mark south cell
		markDFS(board, r, c-1); // mark west cell
		markDFS(board, r, c+1); // mark east cell
	} // markDFS
};

/*
 * Input: XXXX    Output: XXXX
 *		  XOOX			  XXXX
 *		  XXOX			  XXXX
 *		  XOXX			  XOXX
 *
 */
void test1() {
	vector<vector<char>> board {{'X','X','X','X'},
		{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	vector<vector<char>> ret {{'X','X','X','X'},
		{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};
	Solution soln;
	soln.solve(board);
	assert(isArrayEqual(board, ret));
}

int main() {
	test1();
	cout << "Successful\n";
	return 0;
}
