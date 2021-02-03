/* IO, string, and assert */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring> // strcmp()
#include <cassert>

/* STL containers */
#include <vector>
#include <unordered_map>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>

/* STL algorithms such as sort(), reverse(), etc */
#include <algorithm>

/* C++ iterator library, contains back_inserter, etc */
#include <iterator>

/* STL utilities such as make_pair(), move(), swap() */
#include <utility>

/* limits such as INT_MIN, INT_MAX, etc */
#include <climits>

/* types such as isdigit(), isalnum(), etc */
#include <cctype>

/* some functions such as iota(), accumulate(), etc */
#include <numeric>

/* math functions such as pow(), sqrt(), etc */
#include <cmath>

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

template <typename T>
bool isEqual(T a, T b, double tolerance=1e-6) {
    return ((double)(a) - (double)(b) < tolerance);
}

/* template function for printing not equal */
template <typename T>
void printNotEqual (const T &a, const T &b) {
	cout << "[Discrepancy] " << a << " != " << b << endl;
}

/* definition for singly linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode (ListNode *l) {
    if (l == nullptr) {
        cout << "(Empty)\n";
        return;
    }
    while (l) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << "\n";
}

void printListNode (ListNode *a, ListNode *b) {
    cout << "---------------------------------------------\n";
    cout << "1st list: ";
    printListNode(a);
    cout << "2nd list: ";
    printListNode(b);
    cout << "---------------------------------------------\n";
}

bool isListNodeEqual (ListNode *a, ListNode *b) {
    while (a || b) {
        if (a == nullptr || b == nullptr) {
            cout << "Length of ListNode not equal\n";
            printListNode(a, b);
            return false;
        }
        if (a->val != b->val) {
            printListNode(a, b);
            printNotEqual(a->val, b->val);
            return false;
        }
        a = a->next;
        b = b->next;
    } // while
    return true;
}

/* some common utility functions */

/* print out array elements in a line for debugging */
template <typename T>
void printArray (vector<T> a) {
    cout << "---------------------------------------------\n";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n---------------------------------------------\n";
}

template<typename T>
void printArray(vector<T> a, vector<T> b) {
    cout << "---------------------------------------------\n";
    cout << "1st array: ";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "2nd array: ";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
    cout << "---------------------------------------------\n";
}

template <typename T>
void printArray (vector<vector<T> > a) {
    cout << "---------------------------------------------\n";
    for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < a[0].size(); ++j) {
        	cout << a[i][j] << " ";
		}
		cout << "\n";
    }
    cout << "\n---------------------------------------------";
}

/* check if two arrays are identical in length and content */
template <typename T>
bool isArrayEqual (vector<T> a, vector<T> b) {
    if (a.size() != b.size()) {
		cout << "size: " << a.size() << "!=" << b.size() << "\n";
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
			cout << "element: " << a[i] << "!=" << b[i] << "\n";
            printArray(a, b);
            return false;
        }
    }
    return true;
}

template <typename T>
bool isArrayEqual (vector<vector<T> > a, vector<vector<T> > b) {
    if (a.size() != b.size()) { // check number of rows
		cout << "size: " << a.size() << "!=" << b.size() << "\n";
        return false;
    }
	for (int i = 0; i < a.size(); ++i) { // check size of each row
		if (a[i].size() != b[i].size()) {
		    cout << "size: " << a[i].size() << "!=" << b[i].size() << "\n";
			return false;
		}
	}
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
			if (a[i][j] != b[i][j]) {
			    cout << "element: " << a[i][j] << "!=" << b[i][j] << "\n";
                printArray(a[i], b[i]);
        		return false;
        	}
		} // inner for
    } // outer for
    return true;
}

/* check if the first n elements of the two arrays are the same */
template <typename T>
bool isArrayEqual (vector<T> a, vector<T> b, int n) {
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
void printStack (stack<T> stk) {
	vector<T> stk_vec = vector<T>();
    if (stk.empty()) {
        cout << "(Empty)\n";
        return;
    }
	while (!stk.empty()) {
		stk_vec.push_back(stk.top());
		stk.pop();
	}
	reverse(stk_vec.begin(), stk_vec.end());
    cout << "\n---------------------------------------------\n";
	cout << "printing stack from left (top) to right (bottom)\n";
	for (const auto &ele : stk_vec) {
		cout << ele << " ";
	}
    cout << "\n---------------------------------------------";
}

template <typename T>
void printMap (unordered_map<T, T> hash_map) {
    cout << "---------------------------------------------\n";
    if (hash_map.size() == 0) {
        cout << "(Empty map)\n";
    }
    for (auto itr : hash_map) {
        cout << "map[\"" << itr.first << "\"]" << " = " << itr.second << endl;
    }
    cout << "---------------------------------------------\n";
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

/* helper function for isBST */
bool isBST_helper (struct TreeNode *node, int min, int max) {
	if (node == nullptr)
		return true;
	if (node->val < min || node->val > max)
		return false;
	return isBST_helper(node->left, min, node->val) &&
		isBST_helper(node->right, node->val + 1, max);
}

/* check if a given tree is a valid BST efficiently */
bool isBST (struct TreeNode *node) {
	return isBST_helper(node, INT_MIN, INT_MAX);
}

bool isTreeNodeEqual(TreeNode *a, TreeNode *b) {
    if (a == nullptr and b == nullptr) return true;
    if (a == nullptr or b == nullptr) return false;
    if (a->val != b->val) return false;
    return isTreeNodeEqual(a->right, b->right) and isTreeNodeEqual(a->left, b->left);
}
