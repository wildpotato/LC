#include "../include.h"

class Solution {
public:
    struct SortByFirstElement {
        bool operator()(vector<int> a, vector<int> b) {
            return a[0] < b[0];
        }
    };

    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, less<int>>> scores;
        vector<vector<int>> ret;
        constexpr int FIVE = 5;
        for (auto item : items) {
            scores[item[0]].push(item[1]);
        }
        for (auto score : scores) {
            int sum = 0;
            vector<int> top_five(2, 0);
            top_five[0] = score.first;
            for (int i = 0; i < FIVE; ++i) {
                sum += score.second.top();
                score.second.pop();
            }
            top_five[1] = sum / FIVE;
            ret.push_back(top_five);
        }
        sort(ret.begin(), ret.end(), SortByFirstElement());
        return ret;
    }
};

void test1() {
    vector<vector<int>> items {{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}};
    vector<vector<int>> ret {{1,87},{2,88}};
    Solution soln;
    assert(isArrayEqual(ret, soln.highFive(items)));
}

void test2() {
    vector<vector<int>> items {{1,100},{7,100},{1,100},{7,100},{1,100},{7,100},{1,100},{7,100},{1,100},{7,100}};
    vector<vector<int>> ret {{1,100},{7,100}};
    Solution soln;
    assert(isArrayEqual(ret, soln.highFive(items)));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
