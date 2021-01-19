#include "../include.h"

class MinStack {
public:
    struct Data {
	Data(int _v, int _m) : val(_v), min(_m) {}
	int val;
	int min;
    };
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
	int min = x;
	if (s.size() > 0)
	    if (s.top().min < x)
		min = s.top().min;
	s.push(Data(x, min));
    }

    void pop() {
	s.pop();
    }

    int top() {
	return s.top().val;
    }

    int getMin() {
	return s.top().min;
    }
private:
    stack<struct Data> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
void test() {
    MinStack *s = new MinStack();
    s->push(-2);
    assert(s->top() == -2);
    assert(s->getMin() == -2);
    s->push(0);
    assert(s->top() == 0);
    assert(s->getMin() == -2);
    s->push(-3);
    assert(s->top() == -3);
    assert(s->getMin() == -3);
    s->pop();
    s->pop();
    assert(s->getMin() == -2);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
