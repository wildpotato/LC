#include "../include.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int max_profit = 0;
		int min_price_so_far = INT_MAX;
		for (int price : prices) {
			max_profit = max(max_profit, price - min_price_so_far);
			min_price_so_far = min(min_price_so_far, price);
		}
		return max_profit;
    }
};

void test1() {
	vector<int> prices {7,1,5,3,6,4};
	Solution soln;
	assert(soln.maxProfit(prices) == 5);
}

void test2() {
	vector<int> prices {7,6,4,3,1};
	Solution soln;
	assert(soln.maxProfit(prices) == 0);
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
