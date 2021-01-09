/*
 * std::priority_queue (Defined in header <queue>)
 *   template<
 *   class T,
 *   class Container = std::vector<T>,
 *   class Compare = std::less<typename Container::value_type>
 *   > class priority_queue;
 *
 *  Example usage:
 *  std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
 *
 *  A comparator is a callable object. In other words: a function pointer or a lambda closure,
 *  or a class with a suitable operator()
 *
 *  More info: https://stackoverflow.com/questions/41129973/c-how-to-pass-a-comparator-to-stl-functions-correctly
 *
 */

#include "../include.h"

class Solution {
public:
    struct GreaterEuclideanDistance {
        bool operator()(const vector<int> &p1, const vector<int> &p2) const {
            int dist1 = pow(p1[0], 2) + pow(p1[1], 2);
            int dist2 = pow(p2[0], 2) + pow(p2[1], 2);
            return dist1 > dist2;
        }
    }; // GreaterEuclideanDistance

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, GreaterEuclideanDistance> closest_points(points.begin(), points.end());
        vector<vector<int>> ret (K);
        for (int i = 0; i < K; ++i) {
			ret[i] = closest_points.top();
            closest_points.pop();
        }
        return ret;
    }
};

void test1() {
	vector<vector<int>> points {{1, 3}, {2, -2}};
	int K = 1;
	vector<vector<int>> output {{2, -2}};
	Solution soln;
	vector<vector<int>> ret = soln.kClosest(points, K);
	assert(isArrayEqual(ret, output));
}

void test2() {
	vector<vector<int>> points{{3,3},{5,-1},{-2,4}};
	int K = 2;
	vector<vector<int>> output1{{3,3},{-2,4}};
	vector<vector<int>> output2{{-2,4},{3,3}};
	Solution soln;
	vector<vector<int>> ret = soln.kClosest(points, K);
	assert(isArrayEqual(ret, output1) || isArrayEqual(ret, output2));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
