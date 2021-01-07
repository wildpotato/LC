/*
 * Use a map to map alien language to English alphabetical ordering
 *
 * Here is a note on array declaration:
 * https://stackoverflow.com/questions/11490988/c-compile-time-error-expected-identifier-before-numeric-constant
 *
 */

#include "../include.h"

class Solution {
public:
    /* can not do vector<int> char_map outside of a class method */
    vector<int> char_map;
    bool isAlienSorted(vector<string>& words, string order) {
        char_map.resize(26);
        for (int i = 0; i < order.length(); ++i) {
            char_map[(size_t)order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); ++i) {
            if (char_compare(words[i-1], words[i]) > 0) {
                return false;
            }
        }
        return true;
    }
    int char_compare(string &word1, string &word2) {
        int char_compare_val = 0;
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length() && char_compare_val == 0) {
            char_compare_val = char_map[word1[i] - 'a'] - char_map[word2[j] - 'a'];
            i++;
            j++;
        }
        if (char_compare_val == 0) {
            return word1.length() - word2.length();
        }
        return char_compare_val;
    }
};

void test1() {
    vector<string> words {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution soln;
    assert(soln.isAlienSorted(words, order));
}

void test2() {
    vector<string> words {"word","world","row"};
    string order = "worldabcefghijkmnpqstuvxyz";
    Solution soln;
    assert(!soln.isAlienSorted(words, order));
}

void test3() {
    vector<string> words {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    Solution soln;
    assert(!soln.isAlienSorted(words, order));
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
