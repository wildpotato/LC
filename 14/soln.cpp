#include "../include.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            while (size_t pos = strs[i].find(prefix, 0) != 0) {
                prefix.erase(prefix.begin() + prefix.length() - 1);
            }
        }
        return prefix;
    }
};

void test() {
    vector<string> input1 {"flower","flow","flight"};
    vector<string> input2 {"dog","racecar","car"};
    string output1 = "fl";
    string output2 = "";
    Solution soln;
    assert(soln.longestCommonPrefix(input1) == output1);
    assert(soln.longestCommonPrefix(input2) == output2);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
