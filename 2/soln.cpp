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
        while (this->next) {
            if (!other->next) {
                return false;
            }
            if (this->val != other->val) {
                return false;
            }
            this = this->next;
            other = other->next;
        }
        return other->next == nullptr;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode();
        return ret;
    }
};

int main() {
    ListNode l1, l2, ret;
    Solution soln;
    assert(soln.addTwoNumbers(l1, l2)->listEqual(ret));
    delete ret;
}
