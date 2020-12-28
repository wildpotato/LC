#include "../include.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            int water = 0;
            int max_left = -1;
            int max_right = -1;
            for (int j = 0; j < i; ++j) {
                if (height[j] > max_left) {
                    max_left = height[j];
                }
            }
            for (int j = i + 1; j < height.size(); ++j) {
                if (height[j] > max_right) {
                    max_right = height[j];
                }
            }
            water = min(max_left, max_right) - height[i];
            sum += water > 0 ? water : 0;
        }
        return sum;
    }
};

void test1() {
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution soln;
    cout << soln.trap(height) << endl;
    assert(soln.trap(height) == 6);
}


void test2() {
    vector<int> height {4,2,0,3,2,5};
    Solution soln;
    assert(soln.trap(height) == 9);
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
