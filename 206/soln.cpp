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
    ListNode* reverseList(ListNode* head) {
		ListNode *prev = nullptr;
		ListNode *curr = head;
		while (curr) {
			ListNode *tmpNext = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmpNext;
		}
		return prev;
    }
};

void test1() {
	ListNode *l = new ListNode(1, new ListNode(2, new ListNode(3,
				  new ListNode(4, new ListNode(5)))));
	ListNode *r = new ListNode(5, new ListNode(4, new ListNode(3,
				  new ListNode(2, new ListNode(1)))));
	Solution soln;
	assert(isListNodeEqual(r, soln.reverseList(l)));
}

void test2() {
	ListNode *l = nullptr;
	ListNode *r = nullptr;
	Solution soln;
	assert(isListNodeEqual(r, soln.reverseList(l)));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
