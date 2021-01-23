#include "../include.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
		vector<string> ret (n);
		for (int i = 1; i <= n; ++i) {
			string out = "";
			if (i % 3 == 0) {
				out += "Fizz";
			}
			if (i % 5 == 0) {
				out += "Buzz";
			}
			if (out.empty()) {
				out += to_string(i);
			}
			ret[i-1] = out;
		}
		return ret;
    }
};

void test1() {
	vector<string> ret {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
	Solution soln;
	assert(isArrayEqual(soln.fizzBuzz(15), ret));
}

int main() {
	test1();
	cout << "Successful\n";
	return 0;
}
