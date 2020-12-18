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

/* definition for TreeNode */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* some common utility functions */
/* check if two arrays are identical in length and content */
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

template <typename T>
bool isArrayEqual(vector<vector<T>> a, vector<vector<T>> b) {
    if (a.size() != b.size()) { // check number of rows
        return false;
    }
	for (int i = 0; i < a.size(); ++i) { // check size of each row
		if (a[i].size() != b[i].size()) {
			return false;
		}
	}
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
			if (a[i][j] != b[i][j]) {
        		return false;
        	}
		} // inner for
    } // outer for
    return true;
}

/* check if the first n elements of the two arrays are the same */
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

/* print out array elements in a line for debugging */
template <typename T>
void printArray(vector<T> a) {
    cout << "---------------------------------------------\n";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n---------------------------------------------";
}

template <typename T>
void printArray(vector<vector<T>> a) {
    cout << "---------------------------------------------\n";
    for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < a[0].size(); ++j) {
        	cout << a[i][j] << " ";
		}
		cout << "\n";
    }
    cout << "\n---------------------------------------------";
}
