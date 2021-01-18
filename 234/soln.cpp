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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode *fast = head;
        ListNode *slow = head;
        // Use two pointers to locate the mid point of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // second half starts at the next node of the mid point found
        // we reverse it so it is essentially starting backwards
        ListNode *half = reverse(slow->next);
        // use beg as begining of the list, assign it to head
        ListNode *beg = head;
        while (half != nullptr) {
            if (half->val != beg->val) {
                return false;
            }
            half = half->next;
            beg = beg->next;
        }
        // the list reads the same forward as backward, return true
        return true;
    }

    // reverse linked list is itself another LC problem
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

void test1() {
    ListNode *l = new ListNode(1, new ListNode(2));
    Solution soln;
    assert(!soln.isPalindrome(l));
}

void test2() {
    ListNode *l = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    Solution soln;
    assert(soln.isPalindrome(l));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
