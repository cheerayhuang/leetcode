/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: longest_substring_with_at_least_k_repeating_characters.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 22:32:11
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k <= 1) return s.size();

        s = s + '_';
        map<char, int>times_dict;
        for (auto ch : s) {
            ++times_dict[ch];
        }

        auto max = 0;
        auto len = 0;
        map<char, int>tmp_dict;
        for (auto ch : s) {
            if (times_dict[ch] >= k) {
                ++len;
                ++tmp_dict[ch];
            }
            else {
                if (len > max) {
                    auto iter = tmp_dict.begin();
                    for (; iter != tmp_dict.end(); ++iter) {
                        if (iter->second < k) {
                            break;
                        }
                    }
                    if (iter == tmp_dict.end()) max = len;
                }
                len = 0;
                tmp_dict.clear();
            }
        }

        return max;
    }
};

int main() {
    Solution s;

    cout << s.longestSubstring("aaabb", 3) << endl;
    cout << s.longestSubstring("kaaabbc", 2) << endl;
    cout << s.longestSubstring("", 2) << endl;
    cout << s.longestSubstring("", 1) << endl;
    cout << s.longestSubstring("abcdefg", 1) << endl;
    cout << s.longestSubstring("aaabbb", 3) << endl;
    cout << s.longestSubstring("aabcabb", 3) << endl;
    return 0;
}
