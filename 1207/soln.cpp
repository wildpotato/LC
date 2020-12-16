#include "../include.h"


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ele_freq;
        unordered_map<int, bool> freq_present;
        for (int ele : arr) {
            auto itr = ele_freq.find(ele);
            if (itr != ele_freq.end()) {
                itr->second++;
            } else {
                ele_freq[ele] = 1;
            }
        } // for

        for (pair<int, int> p : ele_freq) {
            auto itr = freq_present.find(p.second);
            if (itr != freq_present.end()) {
                return false;
            } else {
                freq_present[p.second] = true;
            }
        } // for

        return true;
    }
};

void test1() {
    Solution soln;
    vector<int> arr {1,2};
    assert(!soln.uniqueOccurrences(arr));
}

void test2() {
    Solution soln;
    vector<int> arr {-3,0,1,-3,1,1,1,-3,10,0};
    assert(soln.uniqueOccurrences(arr));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
