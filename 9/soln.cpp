#include "../include.h"

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		long x_backward = 0;
		int x_copy = x;
		while (x_copy != 0) {
			x_backward *= 10;
			x_backward += (x_copy % 10);
			x_copy /= 10;
		} // while
		return x == x_backward;
    }
};

void test() {
	Solution soln;
	assert(soln.isPalindrome(121));
	assert(!soln.isPalindrome(-121));
	assert(!soln.isPalindrome(10));
	assert(!soln.isPalindrome(-101));
}

int main() {
	test();
	cout << "Successful\n";
}
