/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: add_strings.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 06-29-2017 16:44:23
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        auto len_num1 = num1.length();
        auto len_num2 = num2.length();

        if (len_num2 > len_num1) {
            num1.append(len_num2-len_num1, '0');
        } else {
            num2.append(len_num1-len_num2, '0');
        }

        auto i = 0;
        len_num1 = num1.length();
        auto c = 0;
        while (i < len_num1) {
            auto r = num1[i] + num2[i] - 96 + c;
            c = r / 10;
            r %= 10;
            num1[i] = r + 48;
            ++i;
        }

        if (c > 0) num1.insert(num1.end(), c+48);

        return string(num1.crbegin(), num1.crend());
    }
};

int main() {
    Solution s;

    cout << s.addStrings("456", "111") << endl;
    cout << s.addStrings("4567", "111") << endl;
    cout << s.addStrings("4", "111") << endl;
    cout << s.addStrings("0", "111") << endl;
    cout << s.addStrings("0", "0") << endl;
    cout << s.addStrings("999", "1") << endl;
    cout << s.addStrings("9", "1") << endl;

    return 0;
}
