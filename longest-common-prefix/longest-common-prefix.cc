#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>

using namespace std; 

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.size() == 0) {
            return string();
        }

        vector<string> tmp_strs(strs.size());

        partial_sort_copy(strs.begin(), strs.end(), tmp_strs.begin(), tmp_strs.end(), [](string a, string b) { return a.size() < b.size(); });

        for(size_t i = tmp_strs[0].size(); i > 0; --i) {
            string tmp(tmp_strs[0], 0, i);
            int total = 1;
            for_each(tmp_strs.begin()+1, tmp_strs.end(), [&](string &s) { if (s.find(tmp) == 0) total *= 1; else total *=0; });
            if (total) {
                return tmp;
            }
        }

        return string();
    }
};



int main() {
    Solution s;

    vector<string> v{"abcdefgh", "abcdefg", "abcdefg", "abcdef", "abcde", "abc"};

    string s1("xyzuvw");
    string s2("xyzuv");
    string s3("xyz");

    cout << s.longestCommonPrefix(v) << endl;
    cout << s.longestCommonPrefix({"abc", "abc", "abc"}) << endl;
    cout << s.longestCommonPrefix(vector<string>()) << endl;
    cout << s.longestCommonPrefix({"a", "b", "ccccc"}) << endl;

    return 0;
}
