#include "../include.h"

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    max_area = max(max_area, calArea(points[i], points[j], points[k]));
                }
            }
        }
        return max_area;
    }

    double calArea(vector<int> p1, vector<int> p2, vector<int> p3) {
        double area = abs(0.5 * (p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) +
                p3[0] * (p1[1] - p2[1])));
        return area;
    }
};

void test() {
    vector<vector<int>> points {{0,0},{0,1},{1,0},{0,2},{2,0}};
    Solution soln;
    assert(soln.largestTriangleArea(points) == 2);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
