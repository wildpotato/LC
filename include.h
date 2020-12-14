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
