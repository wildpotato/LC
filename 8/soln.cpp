#include "../include.h"

class Solution {
public:
    int myAtoi(string s) {
		int i = 0, sign = 0;
		bool out_of_range = false;
		long long res = 0;
		while (isspace(s[i])) {
			++i;
		}
		if (s[i] == '+') {
			sign = 1;
			++i;
		} else if (s[i] == '-') {
			sign = -1;
			++i;
		}
		for (; i < s.length(); ++i) {
			if (isdigit(s[i])) {
				res = res * 10 + s[i]-'0';
				if (res > INT_MAX) {
					if (sign < 0) {
						res = INT_MIN;
					} else {
						res = INT_MAX;
					}
					out_of_range = true;
					break;
				}
			} else {
				break;
			}
		}
		if (out_of_range) {
			return res;
		} else {
			res = (sign < 0) ? -1 * res : res;
		}
		return res;
	}
};


int main()
{
    Solution soln;
    assert(soln.myAtoi("42") == 42);
    assert(soln.myAtoi("   -42") == -42);
    assert(soln.myAtoi("4193 with words") == 4193);
    assert(soln.myAtoi("words and 987") == 0);
    assert(soln.myAtoi("-91283472332") == -2147483648);
    assert(soln.myAtoi("-+12") == 0);
    assert(soln.myAtoi("") == 0);
    assert(soln.myAtoi("+1") == 1);
    assert(soln.myAtoi("+-1") == 0);
    assert(soln.myAtoi("  0000000000012345678") == 12345678);
    assert(soln.myAtoi("  -0000000000012345678") == -12345678);
    assert(soln.myAtoi("20000000000000000000") == INT_MAX);
    assert(soln.myAtoi("   +0a32") == 0);
	cout << "Successful\n";
    return 0;
}
