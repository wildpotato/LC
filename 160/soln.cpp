#include "../include.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Uncomment only one of the above method to run
//#define STORE_NODE_ADDR
#define TWO_POINTER

#ifdef STORE_NODE_ADDR
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> nodes_seen;
        while (headA) {
            nodes_seen.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (nodes_seen.find(headB) != nodes_seen.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
#endif

#ifdef TWO_POINTER
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        int lenDiff = 0;
        ListNode *currA = headA;
        ListNode *currB = headB;
        // get length of A
        while (currA) {
            lenA++;
            currA = currA->next;
        }
        // get length of B
        while (currB) {
            lenB++;
            currB = currB->next;
        }
        // get length difference of A and B
        lenDiff = lenA > lenB ? lenA - lenB : lenB - lenA;
        // reset curr pointer to the beginning of list
        currA = headA;
        currB = headB;
        // let the longer list traverse lenDiff nodes so that the two
        // lists will be of equal length till the end
        if (lenA > lenB) {
            while (lenDiff > 0) {
                currA = currA->next;
                lenDiff--;
            }
        } else {
            while (lenDiff > 0) {
                currB = currB->next;
                lenDiff--;
            }
        }
        // now we've simplified the problem down to finding intersection of
        // two lists with equal length and this is easy
        while (currA and currB) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};

#endif
