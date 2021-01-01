#include "../include.h"

struct compareIntervals {
	inline bool operator() (const vector<int> &first_interval, const vector<int> &second_interval)
	{
		return first_interval[0] < second_interval[0];
	}
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int num_intervals = intervals.size();
		if (num_intervals <= 1) {
			return intervals;
		}
		sort(intervals.begin(), intervals.end(), compareIntervals());
		vector<vector<int>> ret;
		vector<int> curr_interval;
		ret.push_back(intervals[0]);
		for (const auto &interval : intervals) {
			curr_interval = ret.back();
			if (curr_interval[1] >= interval[0]) {
				ret[ret.size()-1][1] = max(curr_interval[1], interval[1]);
				//curr_interval[1] = max(curr_interval[1], interval[1]);
			} else {
				ret.push_back(interval);
			}
		}
		return ret;
    }
};

void test1() {
	vector<vector<int>> input {{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> output {{1,6},{8,10},{15,18}};
	Solution soln;
	vector<vector<int>> ret = soln.merge(input);
	printArray(ret);
	assert(isArrayEqual(ret, output));
}

void test2() {
	vector<vector<int >> input{{1,4},{4,5}};
	vector<vector<int >> output{{1,5}};
	Solution soln;
	assert(isArrayEqual(soln.merge(input), output));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
