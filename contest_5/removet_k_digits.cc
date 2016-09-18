/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: removet_k_digits.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-18-2016 11:52:51
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return string("0");
        }

        auto n = num.size() - k;

        auto min_pos = 0;
        auto min = 10;
        auto tmp_str = num;
        string res;
        while (n > 0) {
            for (auto i = 0; tmp_str.size()-i >= n; ++i) {
                if (tmp_str[i]-48 < min) {
                    min = tmp_str[i] - 48;
                    min_pos = i;
                }
            }

            if (res.size() != 0 || min != 0 || n == 1)
                res.append(1, min+48);
            tmp_str.erase(0, min_pos+1);
            n--;
            min = 10;
            min_pos = 0;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("1432219", 3) << endl;
    cout << s.removeKdigits("10", 2) << endl;
    cout << s.removeKdigits("10", 1) << endl;
    string str(10000, '1');
    //cout << s.removeKdigits(str, 5) << endl;
    cout << s.removeKdigits("10200", 1) << endl;

    return 0;
}

