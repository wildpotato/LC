#include "../include.h"

class Solution {
public:
    struct CompareLog{
        const vector<string> &_log;

        CompareLog(const vector<string> &log) : _log(log) {}

        bool operator()(int i, int j) {
            auto l1 = string(_log[i].begin() + _log[i].find_first_of(' ') + 1, _log[i].end());
            auto l2 = string(_log[j].begin() + _log[j].find_first_of(' ') + 1, _log[j].end());
            if (isdigit(l1[0]) && !isdigit(l2[0])) return false;
            else if (!isdigit(l1[0]) && isdigit(l2[0])) return true;
            else if (isdigit(l1[0]) && isdigit(l2[0])) return i - j;
            else {
                int comp = 0;
                comp = strcmp(l1.c_str(), l2.c_str());
                if (comp != 0) return comp;
                l1 = string(_log[i].begin(), _log[i].begin() + _log[i].find_first_of(' '));
                l2 = string(_log[j].begin(), _log[j].begin() + _log[j].find_first_of(' '));
                comp = strcmp(l1.c_str(), l2.c_str());
                if (comp != 0) return comp;
                return i - j;
            }
        }
    };

    vector<string> reorderLogFiles(vector<string>& logs) {
        CompareLog compare(logs);
        sort(logs.begin(), logs.end(), compare);
        return logs;
    }
};

void test1() {
    vector<string> input {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> output {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};
    Solution soln;
    assert(isArrayEqual(soln.reorderLogFiles(input), output));
}

int main() {
    test1();
    cout << "Successful\n";
    return 0;
}
