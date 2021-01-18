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
