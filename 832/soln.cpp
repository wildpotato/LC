#include "../include.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int row = A.size();
		int col = A[0].size();
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col / 2; ++j) {
				swap(A[i][j], A[i][col-j-1]);
			}
			for (int j = 0; j < col; ++j) {
				A[i][j] = A[i][j] ^ 1; // flip num
			}
		}
		return A;
    }
};

void test1() {
	Solution soln;
	vector<vector<int>> input {{1,1,0},{1,0,1},{0,0,0}};
	vector<vector<int>> ret {{1,0,0},{0,1,0},{1,1,1}};
	vector<vector<int>> out = soln.flipAndInvertImage(input);
	//printArray(out);
	assert(isArrayEqual(out, ret));
}

void test2() {
	vector<vector<int>> input {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
	vector<vector<int>> ret {{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}};
	Solution soln;
	assert(isArrayEqual(soln.flipAndInvertImage(input), ret));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
