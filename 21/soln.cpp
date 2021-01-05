#include "../include.h"

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *ret = nullptr;
        while (l1 || l2) {
            if (l1 == nullptr) ret->next = l2;
            else if (l2 == nullptr) ret->next = l1;
            else {
                if (l1->val < l2->val) {
                    ret->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    ret->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
        }
        return ret;
    }
};

void test1() {
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *ret = nullptr;
    Solution soln;
    assert(isListNodeEqual(soln.mergeTwoLists(l1, l2), ret));
}

void test2() {
    ListNode *l1 = nullptr;
    ListNode *l2 = new ListNode(0);
    ListNode *ret = new ListNode(0);
    Solution soln;
    assert(isListNodeEqual(soln.mergeTwoLists(l1, l2), ret));
}

void test3() {
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *ret = new ListNode(1, new ListNode(1, new ListNode(2,
                   new ListNode(3, new ListNode(4, new ListNode(4))))));
    Solution soln;
    cout << "OK\n";
    assert(isListNodeEqual(soln.mergeTwoLists(l1, l2), ret));
    cout << "OK\n";
}

int main() {
    test1();
    cout << "1\n";
    test2();
    cout << "2\n";
    test3();
    cout << "Successful\n";
    return 0;
}
