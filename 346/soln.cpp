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
    }
private:
    queue<int> q;
    int sz;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
void test() {
    MovingAverage *ma = new MovingAverage(3);
    assert(ma->next(1) == 1);
    assert(ma->next(10) == 5.5);
    assert(ma->next(3) == 4.66667);
    assert(ma->next(5) == 6.0);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
