#include "../include.h"

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int n = s.size();
        unordered_map<string, int> doubleSymbol({{"IV", 4}, {"IX",9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}});
        unordered_map<char, int> singleSymbol({{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D', 500},{'M',1000}});
        for (int i = 0; i < n; ++i) {
            bool is_double_symbol = false;
            if (i + 1 < n) {
                auto itr = doubleSymbol.find(s.substr(i, 2));
                if (itr != doubleSymbol.end()) {
                    ret += itr->second;
                    is_double_symbol = true;
                    ++i;
                }
            }
            if (!is_double_symbol) {
                ret += singleSymbol.find(s[i])->second;
            }
        }
        return ret;
    }
};

void test() {
    vector<string> input {"III","IV","IX","LVIII","MCMXCIV"};
    vector<int> ret {3,4,9,58,1994};
    Solution soln;
    for (int i = 0; i < input.size(); ++i) {
        assert(soln.romanToInt(input[i]) == ret[i]);
    }
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
