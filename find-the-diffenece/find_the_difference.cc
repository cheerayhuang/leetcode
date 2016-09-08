/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: find_the_difference.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 11:21:45
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> dict;

        for_each(s.begin(), s.end(), [&dict](char ch) {++dict[ch];});
        for_each(t.begin(), t.end(), [&dict](char ch) {--dict[ch];});

        for (auto ch : t) {
            if (dict[ch] < 0) return ch;
        }
    }
};

int main() {
    return 0;
}


