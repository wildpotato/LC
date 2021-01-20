#include "../include.h"

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ret;
        unordered_map<string, int> hash_map;
        for (auto &cpdomain : cpdomains) {
            size_t pos = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, pos));
            string domain = cpdomain.substr(pos + 1);
            updateHashMap(hash_map, domain, count);
            while ((pos = domain.find('.')) != string::npos) {
                domain.erase(0, pos + 1);
                updateHashMap(hash_map, domain, count);
            }
        }
        for (auto itr : hash_map) {
            ret.push_back(to_string(itr.second) + " " + itr.first);
        }
        return ret;
    }

private:
    void updateHashMap(unordered_map<string, int> &hash_map, string domain,
            int cnt) {
        auto itr = hash_map.find(domain);
        if (itr != hash_map.end()) {
            itr->second += cnt;
        } else {
            hash_map[domain] = cnt;
        }
    }
};

void test1() {
    vector<string> input {"9001 discuss.leetcode.com"};
    vector<string> output {"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"};
    Solution soln;
    assert(is_permutation(output.begin(), output.end(), soln.subdomainVisits(input).begin()));
}

void test2() {
    vector<string> input {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> output {"901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"};
    Solution soln;
    assert(is_permutation(output.begin(), output.end(), soln.subdomainVisits(input).begin()));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
