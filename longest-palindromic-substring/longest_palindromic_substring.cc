/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: longest_palindromic_substring.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 10:58:11
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {

private:
    vector<pair<size_t, size_t>> FindPalindromicPoint_(const string& s) {
        vector<pair<size_t, size_t>> v;
        for(auto iter = s.begin(); iter != s.end()-1; ++iter) {
            if (iter != s.begin() && *(iter-1) == *(iter+1)) {
                v.push_back(make_pair(distance(s.begin(), iter-1), distance(s.begin(), iter+1)));
            }

            if (*iter == *(iter+1)) {
                v.push_back(make_pair(distance(s.begin(), iter), distance(s.begin(), iter+1)));
            }
        }

        return v;
    }

public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;

        auto ranges = FindPalindromicPoint_(s);
        auto max = 0;
        auto max_range = make_pair(s.cend(), s.cend());

        for (auto range : ranges) {
            auto r_iter = s.begin();
            advance(r_iter, range.first);

            auto iter = s.begin();
            advance(iter, range.second);

            auto len = distance(r_iter, iter) + 1;

            auto current_estimated_len = min(r_iter - s.begin(), s.end()-iter-1) * 2 + len;
            if (current_estimated_len < max) continue;

            while(r_iter != s.begin() && iter != s.end()-1 && *(--r_iter) == *(++iter)) {
                len += 2;
            }

            if (*r_iter != *iter) {
                *r_iter++;
            }
            else {
                iter++;
            }

            if (len > max) {
                max = len;
                max_range = make_pair(r_iter, iter);
            }
            if (max == s.length()) break;
        }

        return string(max_range.first, max_range.second);
    }
};

int main() {

    Solution s;
    cout << s.longestPalindrome("aaaabaaaacdefghizk") << endl;
    cout << s.longestPalindrome("abacbaefghizk") << endl;
    cout << s.longestPalindrome("aabbccbbaa") << endl;
    cout << s.longestPalindrome("bb") << endl;
    cout << s.longestPalindrome("a") << endl;

    return 0;
}
