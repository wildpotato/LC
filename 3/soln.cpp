#include "../include.h"

/*
 * Uncomment if we want to print out debug messges
 */
//#define DEBUG


/*
 * Choose which version to compile, leave the version we want uncommented and comment
 * out every other version (distinguish by time complexity)
 */
//#define Oofn3
#define Oofn1


//var lengthOfLongestSubstring = function(s) {
//  let leftWindow = 0;
//  let longest = 0;
//  let counts = {};
//
//  for (let rightWindow = 0; rightWindow < s.length; ) {
//    if (!counts[s[rightWindow]]) {
//      counts[s[rightWindow]] = 0;
//    }
//
//    counts[s[rightWindow]] += 1;
//
//    if (Object.values(counts).some((element) => element > 1)) {
//      counts[s[leftWindow]] -= 1;
//      leftWindow += 1;
//    }
//
//    longest = Math.max(longest, rightWindow - leftWindow + 1);
//    rightWindow += 1;
//  }
//
//  return longest;
//};
#ifdef Oofn3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
		int bestSoFar = 1;
		for (unsigned int i = 0; i < s.length()-1; ++i) {
			int soFar = 1;
#ifdef DEBUG
			cout << "---------\n";
#endif
            for (unsigned int j = i + 1; j < s.length(); ++j) {
				string sub = s.substr(i, j-i);
#ifdef DEBUG
                cout << "(i=" << i << ",j=" << j << "), " << "sub=" << sub << "\n";
#endif
                auto itr = sub.find(s[j], 0);
                if (itr != string::npos) {
                //if (s.substr(i, j-i).find(s[j]) != string::npos) {
#ifdef DEBUG
                    cout << "Found '" << s[itr] << "'\n";
#endif
					break;
				}
				else {
					soFar++;
#ifdef DEBUG
                    cout << "'" << s[j] << "' Not found, increment soFar=" << soFar << "\n";
#endif
					if (soFar > bestSoFar) {
						bestSoFar = soFar;
					}
				}
			}
#ifdef DEBUG
            cout << "This round soFar=" << soFar << "\n";
#endif
		}
#ifdef DEBUG
		cout << "bestSoFar=" << bestSoFar << "\n";
#endif
		return bestSoFar;
    }

};
#endif
#ifdef Oofn1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); ++i) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
#endif

void test1() {
    string s = "abcabcbb";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 3);
}

void test2() {
    string s = "bbbbb";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 1);
}

void test3() {
    string s = "pwwkew";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 3);
}

void test4() {
    string s = "";
    Solution soln;
    assert(soln.lengthOfLongestSubstring(s) == 0);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "Successful\n";
    return 0;
}
