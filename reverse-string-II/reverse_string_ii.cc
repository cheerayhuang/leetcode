/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: reverse_string_ii.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 06-22-2017 22:28:32
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.length() <= k) {
            reverse(s.begin(), s.end());
            return s;
        }
        if (s.length() < 2*k) {
            reverse(s.begin(), s.begin()+k);
            return s;
        }

        for (auto i = 0; i < s.length(); ++i) {
            if (i % (2*k) == 0) {
                auto end_iter = s.begin() + i + k;
                if (i + k > s.length()) {
                    end_iter = s.end();
                }

                reverse(s.begin()+i, end_iter);
            }
        }


        return s;
    }
};

int main() {
    return 0;
}
