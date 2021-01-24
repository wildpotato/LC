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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            if (curr->val == val) {
                prev->next = next;
            } else {
                prev = curr;
            }
            curr = next;
        }
        return dummy->next;
    }
};

void test1() {
    ListNode * l1 = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    ListNode * ret1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution soln;
    assert(isListNodeEqual(soln.removeElements(l1, 6), ret1));
}

void test2() {
    ListNode * l2 = nullptr;
    ListNode * ret2 = nullptr;
    Solution soln;
    assert(isListNodeEqual(soln.removeElements(l2, 0), ret2));
}

void test3() {
    ListNode * l3 = new ListNode(1);
    ListNode * ret3 = nullptr;
    Solution soln;
    assert(isListNodeEqual(soln.removeElements(l3, 1), ret3));
}

void test4() {
    ListNode * l3 = new ListNode(1, new ListNode(1));
    ListNode * ret3 = nullptr;
    Solution soln;
    assert(isListNodeEqual(soln.removeElements(l3, 1), ret3));
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "Successful\n";
    return 0;
}
