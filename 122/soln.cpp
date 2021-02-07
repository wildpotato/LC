#include "../include.h"

/*
 *  The key to obtaining max profix is to ensure
 *  that we participate in each valley-peak pair
 *  where each valley-peak pair is a pair of low
 *  price and high price where the lows price comes
 *  before the high price. (they are relative)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int profit = 0;
		int valley = prices[0];
		int peak = prices[0];
		int n = prices.size();
		int i = 0;
		while (i < n-1) {
			// find valley
			while (i < n-1 and prices[i] >= prices[i+1]) { i++; }
			valley = prices[i];
			// find peak
			while (i < n-1 and prices[i] <= prices[i+1]) { i++; }
			peak = prices[i];
			profit += peak - valley;
		}
		return profit;
    }
};

void test() {
	vector<int> prices1 {7,1,5,3,6,4};
	vector<int> prices2 {1,2,3,4,5};
	vector<int> prices3 {7,6,4,3,1};
	Solution soln;
	assert(isEqual(soln.maxProfit(prices1), 7));
	assert(isEqual(soln.maxProfit(prices2), 4));
	assert(isEqual(soln.maxProfit(prices3), 0));
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
