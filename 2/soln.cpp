/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool listEqual(ListNode *other) {
        ListNode *tmp = this;
		while (tmp->next) {
            if (!other->next) {
				return false;
            }
            if (tmp->val != other->val) {
                return false;
            }
            tmp = tmp->next;
            other = other->next;
        }
        return other->next == nullptr;
    }

    void printList() {
        ListNode *tmp = this;
        while (tmp) {
            cout << tmp->val << "->";
            tmp = tmp->next;
        }
        cout << "nullptr" << endl;
    }
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        else if (!l1) return l2;
        else if (!l2) return l1;
        int carry = 0;
        auto ret = l1;
        auto l1end = l1;
        while (l1 || l2) {
            if (l1 && l2) {
                l1->val += l2->val + carry;
            } else if (l2) {
                l1end->next = new ListNode(l2->val + carry);
                l1 = l1end->next;
            } else l1->val += carry;
            if (l1->val > 9) {
                carry = 1;
                l1->val -= 10;
            } else carry = 0;
            l1end = l1;
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry == 1) l1end->next = new ListNode(1);
        return ret;
    }
};

void test1() {
    ListNode *l1 = new ListNode();
	ListNode *l2 = new ListNode();
	ListNode *ret = new ListNode();
    Solution soln;
    assert(soln.addTwoNumbers(l1, l2)->listEqual(ret));
	delete l1, l2, ret;
}

void test2() {
    ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *ret = new ListNode(3);
    Solution soln;
    assert(soln.addTwoNumbers(l1, l2)->listEqual(ret));
	delete l1, l2, ret;
}

void test3() {
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
	ListNode *ret = new ListNode(7, new ListNode(0, new ListNode(8)));
    Solution soln;
    assert(soln.addTwoNumbers(l1, l2)->listEqual(ret));
	delete l1, l2, ret;
}

void test4() {
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9,
    new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9,
    new ListNode(9))));
    ListNode *ret = new ListNode(8, new ListNode(9, new ListNode(9,
    new ListNode(9, new ListNode(0, new ListNode(0, new ListNode(0,
					new ListNode(1))))))));
    Solution soln;
    assert(soln.addTwoNumbers(l1, l2)->listEqual(ret));
    delete l1, l2, ret;
}

void test5() {
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(3,
                    new ListNode(4))));
    ListNode *l2 = new ListNode(1, new ListNode(1));
    ListNode *ret = new ListNode(2, new ListNode(3, new ListNode(3,
                    new ListNode(4))));
    Solution soln;
    //soln.addTwoNumbers(l1,l2)->printList();
    assert(soln.addTwoNumbers(l1, l2)->listEqual(ret));
    delete l1, l2, ret;
}

int main() {
	test1();
	test2();
	test3();
	test4();
    test5();
	cout << "Successful" << endl;
}
