/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: find_all_anagrams_in_a_string.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-21-2017 19:01:03
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size() || s.size() == 0) return vector<int>(0);

        vector<int> res;

        if (p.size() == 0) {
            for(auto i = 0; i <= s.size(); ++i) res.push_back(i);
            return res;
        }

        auto len_p = p.size();
        vector<bool> prev_result(s.size()-len_p, false);

        if (is_permutation(p.begin(), p.end(), string(s, 0, len_p).begin())) {
            prev_result[0] = true;
            res.push_back(0);
        }

        for (auto i = 1; i <= s.size()-len_p; ++i) {
            auto cur_str = string(s, i, len_p);
            if (s[i-1] == s[i+len_p-1]) {
                prev_result[i] = prev_result[i-1];
            } else {
                prev_result[i] = is_permutation(p.begin(), p.end(), cur_str.begin());
            }

            if (prev_result[i]) res.push_back(i);
        }

        return res;

    }
};

int main() {
    Solution s;

    auto res = s.findAnagrams("cbaebabacd", "abc");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("abab", "ab");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("abab", "a");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("aaaaaa", "a");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("abce", "eabc");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("", "eabc");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("abc", "eabc");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.findAnagrams("abc", "");
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    const string letters("abcdefghijklmnopqrstuvwxyz");
    string s1, s2;
    for (auto i = 0; i < 773; ++i) {
        s1.append(letters);
        if (i < 100)
            s2.append(letters);
    }

    res = s.findAnagrams(s1, s2);
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    s1.append("ab");
    s2.append("ba");
    res = s.findAnagrams(s1, s2);
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    return 0;
}

