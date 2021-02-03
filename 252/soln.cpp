#include "../include.h"

/*
 *  This problem illustrates two very good and practical programming tips in C++
 *
 *  1. How to write a custom comparator and pass it into std::sort
 *
 *  2. Inside a comparator, if the objects being compared are not of primitive types,
 *     it will be way more efficient to pass them by reference; specifically, if they
 *     are both custom types and we wish not to change them during comparison (most of
 *     the time we don't ever change the objects for the purpose of comparing them),
 *     it is good practice to pass them by const reference.
 *
 */

class Solution {
public:
    struct CompareStartTime{
        bool operator()(const vector<int> &meeting1, const vector<int> &meeting2) {
            return meeting1[0] < meeting2[0];
        }
    };
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), CompareStartTime());
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};

void test() {
    vector<vector<int>> intervals1 {{0,30},{5,10},{15,20}};
    vector<vector<int>> intervals2 {{7,10},{2,4}};
    Solution soln;
    assert(!soln.canAttendMeetings(intervals1));
    assert(soln.canAttendMeetings(intervals2));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
