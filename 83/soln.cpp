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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
		ListNode *curr_node = head, *next_next;
		while (curr_node->next) {
			if (curr_node->next->val == curr_node->val) {
				next_next = curr_node->next->next;
				curr_node->next = next_next;
			} else {
                curr_node = curr_node->next;
			}
        } // while
        return head;
    }
};

void test1() {
    ListNode *input = new ListNode(1, new ListNode(1, new ListNode(2)));
    ListNode *output = new ListNode(1, new ListNode(2));
    Solution soln;
    assert(isListNodeEqual(soln.deleteDuplicates(input), output));
}

void test2() {
    ListNode *input = new ListNode(1, new ListNode(1, new ListNode(2, \
                      new ListNode(3, new ListNode(3)))));
    ListNode *output = new ListNode(1, new ListNode(2, new ListNode(3)));
    Solution soln;
    assert(isListNodeEqual(soln.deleteDuplicates(input), output));
}

void test3() {
    ListNode *input = nullptr;
    ListNode *output = nullptr;
    Solution soln;
    assert(isListNodeEqual(soln.deleteDuplicates(input), output));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
