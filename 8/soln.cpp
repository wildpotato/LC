#include "../include.h"

class Solution {
public:
    int myAtoi(string s) {
        int beg = 0, len = 0;
        long ret;
        bool detect_num_start = false;
        int detect_neg_sign = -1;
        int detect_pos_sign = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                if (!detect_num_start) {
                    if (detect_neg_sign >= 0 && detect_pos_sign >= 0) {
                        return 0;
                    }
                    detect_num_start = true;
                    if (detect_neg_sign >= 0 && detect_neg_sign == i-1) {
                        beg = i-1;
                        len = 2;
                    } else if (detect_pos_sign >= 0 && detect_pos_sign == i-1) {
                        beg = i-1;
                        len = 2;
                    } else {
                        detect_neg_sign = -1;
                        detect_pos_sign = -1;
                        beg = i;
                        len++;
                    }
                } else {
                    len++;
                }
            } else {
                if (detect_num_start) {
                    break; // get substr for num already
                }
                else if (isspace(s[i]) && !detect_num_start) {
                    continue;
                } else if (!detect_num_start && s[i] == '-') {
                    detect_neg_sign = i;
                } else if (!detect_num_start && s[i] == '+') {
                   detect_pos_sign = i;
                } else {
                    return 0;
                }
            }
        }

        string num = s.substr(beg, len);
        if (num.length() == 0) {
            return 0;
        }
        num = (num[0] == '+' || num[0] == '-') ? num.erase(1, num.find_first_not_of('0', num.size()-1)) :
            num.erase(0, num.find_first_not_of('0', num.size()));
        len = num.length();
        cout << "|" << num << "|" << endl;
        cout << "len=" << len << endl;
        if (len == 0) {
            return 0;
		}
        if (len >= 11) { // out of range for sure
          if (num[0] == '-') {
              return INT_MIN;
          }
          return INT_MAX;
        }
        ret = stol(num);
        cout << "num = '" << ret << "'" << endl;
        if (ret > INT_MAX) {
            return INT_MAX;
        } else if (ret < INT_MIN) {
            return INT_MIN;
        } else {
            return ret;
        }
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
    cout << "Successful\n";
    return 0;
}
