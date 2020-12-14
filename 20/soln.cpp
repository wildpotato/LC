#include "../include.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                left.push(c);
            } else {
                if (left.empty()) {
                    return false;
                }
                char curr = left.top();
                left.pop();
                switch (c) {
                    case '}':
                        if (curr != '{') {
                            return false;
                        }
                        break;
                    case ']':
                        if (curr != '[') {
                            return false;
                        }
                        break;
                    case ')':
                        if (curr != '(') {
                            return false;
                        }
                        break;
                    default:
                        return false;
                } // switch
            }
        }
        return left.empty();
    }
};

void test() {
    Solution soln;
    assert(soln.isValid("()"));
    assert(soln.isValid("()[]{}"));
    assert(!soln.isValid("(]"));
    assert(!soln.isValid("([)]"));
    assert(soln.isValid("{[]}"));
    assert(!soln.isValid("{"));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
