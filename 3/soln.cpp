#include "../include.h"

/*
 * Uncomment if we want to print out debug messges
 */
//#define DEBUG


/*
 * Choose which version to compile, leave the version we want uncommented and comment
 * out every other version (distinguish by time complexity)
 */
#define Oofn3


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
