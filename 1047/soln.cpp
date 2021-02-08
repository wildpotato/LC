#include "../include.h"

class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> deq;
        for (int i = 0; i < S.length(); ++i) {
            if (deq.empty()) {
                deq.push_back(S[i]);
            } else {
                int prev = deq.back();
                if (prev != S[i]) {
                    deq.push_back(S[i]);
                } else {
                    deq.pop_back();
                }
            }
        }
        return string(deq.begin(), deq.end());
    }
};

void test() {
    string input = "abbaca";
    string ret = "ca";
    Solution soln;
    string output = soln.removeDuplicates(input);
    assert(output == ret);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
