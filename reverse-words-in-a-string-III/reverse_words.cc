/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: reverse_words.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-15-2017 19:48:24
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        auto res = string();
        auto p = s.find(' ');

        while (p != string::npos) {
            auto part = s.substr(0, p);
            reverse(part.begin(), part.end());
            s = s.substr(p+1);
            res = res + part + ' ';

            p = s.find(' ');
        }

        res += string(s.crbegin(), s.crend());

        return res;
    }
};

int main() {

    Solution s;

    cout << s.reverseWords("Let's take LeetCode contest") << endl;
    cout << s.reverseWords("a") << endl;
    cout << s.reverseWords("a b cd") << endl;

    return 0;
}

