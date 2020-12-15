#include "../include.h"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (string op : ops) {
            if (op == "C") {
                scores.pop_back();
            } else if (op == "D") {
                scores.push_back(scores.back() * 2);
            } else if (op == "+") {
                int score_1 = scores.back();
                scores.pop_back();
                int score_2 = scores.back();
                scores.pop_back();
                scores.push_back(score_2);
                scores.push_back(score_1);
                scores.push_back(score_1 + score_2);
            } else {
                scores.push_back(stoi(op));
            }
        } // for
        return accumulate(scores.begin(), scores.end(), 0);
    }
};

void test() {
    Solution soln;
    vector<string> ops1 {"5","2","C","D","+"};
    vector<string> ops2 {"5","-2","4","C","D","9","+","+"};
    vector<string> ops3 {"1"};
    assert(soln.calPoints(ops1) == 30);
    assert(soln.calPoints(ops2) == 27);
    assert(soln.calPoints(ops3) == 1);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
