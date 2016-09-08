/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ransom_note.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 15:08:27
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> dict;
        for_each(magazine.begin(), magazine.end(), [&dict](char ch) { ++dict[ch]; });

        for (auto ch : ransomNote) {
            if (--dict[ch] < 0) return false;
        }

        return true;
    }
};


int main() {
    Solution s;

    cout << s.canConstruct("aa", "aab") << endl;
    cout << s.canConstruct("a", "b") << endl;
    cout << s.canConstruct("aa", "ab") << endl;

    return 0;
}
