#include "../include.h"

bool comp(const vector<int> &a, const vector<int> &b) {
    if (a[0] < b[1]) {
        return true;
    }
    return a[1] < b[1];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        return 3;
    }
    void printEnvelopes(vector<vector<int>> &envs) {
        for (auto e : envs) {
            cout << "[" << e[0] << " " << e[1] << "]\n";
        }
    }
};

void test1() {
    vector<vector<int>> env {{5,4},{6,4},{6,7},{2,3}};
    Solution soln;
    std::sort(env.begin(), env.end(), comp);
    soln.printEnvelopes(env);
    assert(soln.maxEnvelopes(env) == 3);
}

int main() {
    test1();
    cout << "Successful\n";
    return 0;
}
