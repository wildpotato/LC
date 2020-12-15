#include "../include.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int s : stones) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            int max_1st = pq.top();
            pq.pop();
            int max_2nd = pq.top();
            pq.pop();
            pq.push(max_1st - max_2nd);
        }
        return pq.top();
    }
};

void test1() {
    vector<int> stones {2,7,4,1,8,1};
    Solution soln;
    assert(soln.lastStoneWeight(stones) == 1);
}

void test2() {
    vector<int> stones {9};
    Solution soln;
    assert(soln.lastStoneWeight(stones) == 9);
}

void test3() {
    vector<int> stones {2,2};
    Solution soln;
    assert(soln.lastStoneWeight(stones) == 0);
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
