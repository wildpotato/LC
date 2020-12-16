/* IO, string, and assert */
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

/* STL containers */
#include <vector>
#include <unordered_map>
#include <deque>
#include <stack>
#include <queue>
#include <map>

/* STL algorithms such as sort(), etc */
#include <algorithm>

/* limits such as INT_MIN, INT_MAX, etc */
#include <climits>

/* types such as isdigit, isalphanumeric, etc */
#include <cctype>

/* some functions such as iota, accumulate, etc */
#include <numeric>

/* use std namespace so we don't need to type std:: */
using namespace std;

/* Leetcode speedup tricks */
//static const auto io_sync_off = []()
//{
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

/* some commonly defined structs */
/* definition for singly linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isListNodeEqual(ListNode *a, ListNode *b) {
    while (a || b) {
        if (a == nullptr || b == nullptr) {
            return false;
        }
        if (a->val != b->val) {
            return false;
        }
        a = a->next;
        b = b->next;
    } // while
    return true;
}

/* some common utility functions */
/* check if the two array are identical */
template <typename T>
bool isArrayEqual(vector<T> a, vector<T> b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

/* check if the first n elements of the two array are equal */
template <typename T>
bool isArrayEqual(vector<T> a, vector<T> b, int n) {
    if (n < 0 || a.size() < n || b.size() < n) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void printArray(vector<T> a) {
    cout << "---------------------------------------------\n";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n---------------------------------------------";
}
