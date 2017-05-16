/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: longest_uncommon_subsequence_I.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-16-2017 21:05:18
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;


class Solution {
    public:
        int findLUSlength(string a, string b) {
            auto len_a = a.length();
            auto len_b = b.length();

            if (len_a != len_b) {
                return (len_a > len_b ? len_a : len_b);
            }

            if (a != b) return len_a;

            return -1;
        }
};

int main() {

    return 0;
}



