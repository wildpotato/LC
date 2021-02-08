#include "../include.h"

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        old_color = image[sr][sc];
        new_color = newColor;
        row_size = image.size();
        col_size = image[0].size();
        if (new_color != old_color) {
            floodFillHelper(image, sr, sc);
        }
        return image;
    }

    void floodFillHelper(vector<vector<int>> &image, int r, int c) {
        if (image[r][c] == old_color) {
            image[r][c] = new_color;
            if (r-1 >= 0) {
                floodFillHelper(image, r-1, c);
            }
            if (r+1 < row_size) {
                floodFillHelper(image, r+1, c);
            }
            if (c-1 >= 0) {
                floodFillHelper(image, r, c-1);
            }
            if (c+1 < col_size) {
                floodFillHelper(image, r, c+1);
            }
        } else {
            return;
        }
    }

private:
    int old_color = 0;
    int new_color = 0;
    int row_size = 0;
    int col_size = 0;
};

void test1() {
    vector<vector<int>> img {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> ret {{2,2,2},{2,2,0},{2,0,1}};
    Solution soln;
    assert(isArrayEqual(ret, soln.floodFill(img, 1, 1, 2)));
}

void test2() {
    vector<vector<int>> img {{0,0,0},{0,1,1}};
    vector<vector<int>> ret (img);
    Solution soln;
    assert(isArrayEqual(ret, soln.floodFill(img, 1, 1, 1)));
}
int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
