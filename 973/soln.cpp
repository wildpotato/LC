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
        priority_queue<vector<int>, vector<int>, GreaterEuclideanDistance(vector<int>, vector<int>)> closest_points;
        vector<vector<int>> ret (K);
        for (const vector<int> &point : points) {
            closest_points.push(point);
        }
        for (int i = 0; i < K; ++i) {
            ret.push_back(closest_points.top());
            closest_points.pop();
        }
        return ret;
    }
};
