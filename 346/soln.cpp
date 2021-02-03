#include "../include.h"

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
    }

    double next(int val) {
        if (q.size() == sz) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return (double) sum / double(q.size());
    }
private:
    queue<int> q;
    int sz = 0;  // somehow if we don't initialize to zero it won't pass Leetcode
    int sum = 0; // somehow if we don't initialize to zero it won't pass Leetcode
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

void test() {
    MovingAverage *ma = new MovingAverage(3);
    assert(isEqual(ma->next(1), 1.00000));
    assert(isEqual(ma->next(10), 5.50000));
    assert(isEqual(ma->next(3), 4.66667));
    assert(isEqual(ma->next(5), 6.00000));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
