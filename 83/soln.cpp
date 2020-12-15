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
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode *curr_node = head, *tmp_node;
		int curr_val = head->value;
		while (curr_node->next) {
			if (curr_node->next->val == curr_val) {
				tmp_node = curr_node->next;
				curr_node->next = tmp_node->next;
			} else {
				curr_val = curr_node->val;
			}
    }
};
