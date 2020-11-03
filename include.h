/* IO, string, and assert */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
#include <string>
using std::string;
#include <cassert>

/* STL containers */
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;
#include <deque>
using std::deque;
#include <queue>
using std::queue;
using std::priority_queue;
#include <map>
using std::map;

/* limits such as INT_MIN, INT_MAX, etc */
#include <climits>

/* types such as isdigit, isalphanumeric, etc */
#include <cctype>

/* Leetcode speedup tricks */
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
