/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: covert_num_to_hex.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-25-2016 10:03:58
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    const string base_num = "0123456789abcdef";

public:
    string toHex(int n) {

        if (n == 0) return string("0");

        auto res = string();
        unsigned int num = static_cast<unsigned>(n);

        while (num > 0) {
            auto m = (num & 0xf);
            res.insert(res.end(), base_num[m]);
            num = num >> 4;
        }

        reverse(res.begin(), res.end());
        return std::move(res);
    }
};

int main() {
    Solution s;

    cout << s.toHex(50) << endl;
    cout << s.toHex(0) << endl;
    cout << s.toHex(INT_MAX) << endl;
    cout << s.toHex(INT_MIN) << endl;
    cout << s.toHex(-1) << endl;
    cout << hex << INT_MIN << endl;
    return 0;
}



