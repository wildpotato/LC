/*
 * Patience Sorting
 *
 * https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
 *
 * The patience sort solution follows the gist of the patience game. Specifically, we simply need
 * to keep track of the number of piles and the top cards of each pile. The rest is irrevalent to
 * solving the LIS problem. Upon each card dealt, we compare it with the top cards and create a
 * new pile if all top cards are less than the card just dealt. We also observe that the top cards
 * are in sorted order which allows us to employ binary search when finding the right pile to place
 * the card just dealt. After we exhaust all the cards (or numbers in this case), the number of piles
 * is equal to the length of the LIS and that solves this problem!
 *
 * The runtime complexity is O(n logk) where n is the number of cards and k is the number of piles
 * The space complexity is approximately O(n)
 *
 */

#include "../include.h"

/* use only one of the following implementations at a time */
#define USE_PATIENCE_SORT
//#define USE_DP_O_N_SQUARE

#ifdef USE_PATIENCE_SORT
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(), 0);
        int size = 0;

        for(int x: nums) {
            int i = 0, j = size;
            while(i < j) {
                int m = (i + j) / 2;
                if(tails[m] < x) {
                    i = m + 1;
                } else {
                    j = m;
                }
            }
            tails[i] = x;
            if(i == size) ++size;
        }

        return size;
    }
};

#endif
#ifdef USE_DP_O_N_SQUARE
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		size_t n = nums.size();
		int ret = 0;
		vector<int> dp(n + 1, 1);
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ret = max(ret, dp[i]);
		}
        return ret;
    }
};
#endif

void test1() {
    Solution soln;
    vector<int> nums {10,9,2,5,3,7,101,18};
    assert(soln.lengthOfLIS(nums) == 4);
}

void test2() {
    Solution soln;
    vector<int> nums {0,1,0,3,2,3};
    assert(soln.lengthOfLIS(nums) == 4);
}

void test3() {
    Solution soln;
    vector<int> nums {7,7,7,7,7,7,7};
    assert(soln.lengthOfLIS(nums) == 1);
}

int main() {
    test1();
    cout << "Successful\n";
    return 0;
}
