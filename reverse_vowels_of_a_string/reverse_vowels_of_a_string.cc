/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: reverse_vowels_of_a_string.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-18-2016 16:13:30
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {

private:
    unordered_set<char> set_{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

public:
    string reverseVowels(string s) {
        string vowels;
        for (auto ch : s) {
            if (set_.count(ch)) {
                vowels.insert(vowels.end(), ch);
            }
        }

        if (vowels.size() <= 1) return s;
        vowels.assign(vowels.rbegin(), vowels.rend());

        string res;
        auto i = 0;
        for (auto ch : s) {
            if (set_.find(ch) != set_.end())
                res.insert(res.size(), 1, vowels[i++]);
            else
                res.insert(res.size(), 1, ch);
        }

        return res;
    }
};

int main() {
    Solution s;

    cout << s.reverseVowels("hello") << endl;
    cout << s.reverseVowels("leetcode") << endl;
    cout << s.reverseVowels("aA") << endl;

    return 0;
}

