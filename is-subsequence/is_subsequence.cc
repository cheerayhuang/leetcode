/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: is_subsequence.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 20:08:22
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {

public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        if (t.size() == 0) return false;
        size_t pos = 0;
        for (auto ch : s) {
            pos = t.find(ch, pos);
            if (pos == string::npos) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution s;

    cout << s.isSubsequence("abc", "aaaaakkkbkskdfc") << endl;
    cout << s.isSubsequence("abc", "cbaaaaa") << endl;
    cout << s.isSubsequence("a", "cbaaaaa") << endl;
    return 0;
}


