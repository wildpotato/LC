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
        ListNode *ret = new ListNode(INT_MIN); // dummy head
        ListNode *curr = ret;
        while (l1 || l2) {
            if (l1 == nullptr) {
                curr->next = l2;
                break;
            } else if (l2 == nullptr) {
                curr->next = l1;
                break;
            } else {
                if (l1->val < l2->val) {
                    curr->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    curr->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                curr = curr->next;
            }
        }
        return ret->next;
    }
};

void test1() {
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *ret = nullptr;
    Solution soln;
    assert(isListNodeEqual(soln.mergeTwoLists(l1, l2), ret));
    //delete l1, l2, ret;
}

void test2() {
    ListNode *l1 = nullptr;
    ListNode *l2 = new ListNode(0);
    ListNode *ret = new ListNode(0);
    Solution soln;
    assert(isListNodeEqual(soln.mergeTwoLists(l1, l2), ret));
    //delete l1, l2, ret;
}

void test3() {
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *ret = new ListNode(1, new ListNode(1, new ListNode(2,
                   new ListNode(3, new ListNode(4, new ListNode(4))))));
    Solution soln;
    ListNode *merged = soln.mergeTwoLists(l1, l2);
    //printListNode(merged, ret);
    assert(isListNodeEqual(merged, ret));
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
