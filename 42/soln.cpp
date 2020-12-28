#include "../include.h"

/* toggle one of the following methods at a time */
//#define BRUTE_FORCE
#define DYNAMIC_PROGRAMMING

#ifdef BRUTE_FORCE
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
#endif

#ifdef DYNAMIC_PROGRAMMING
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
		if (n < 3) return 0;
		int water = 0;
		vector<int> left_max(n);
		vector<int> right_max(n);
		left_max[0] = height[0];
		for (int i = 1; i < n; ++i) {
			left_max[i] = max(left_max[i-1], height[i]);
		}
		right_max[n - 1] = height[n - 1];
		for (int i = n - 2;  i >= 0; --i) {
			right_max[i] = max(right_max[i+1], height[i]);
		}
		for (int i = 1; i < n - 1; ++i) {
			water += min(left_max[i], right_max[i]) - height[i];
		}
		return water;
	}
};
#endif

void test1() {
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution soln;
    cout << soln.trap(height) << endl;
    assert(soln.trap(height) == 6);
}


void test2() {
    vector<int> height {4,2,0,3,2,5};
    Solution soln;
    cout << soln.trap(height) << endl;
    assert(soln.trap(height) == 9);
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
