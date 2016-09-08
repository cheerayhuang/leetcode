/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: excel_sheet_column_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 14:44:59
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {

        auto res = 0;

        auto base = 1;
        for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
            res = res + (*iter - 64) * base;
            base *= 26;
        }

        return res;
    }
};

int main() {

    Solution s;

    cout << s.titleToNumber("AA") << endl;
    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("F") << endl;
    cout << s.titleToNumber("X") << endl;
    cout << s.titleToNumber("AZ") << endl;
    cout << s.titleToNumber("BA") << endl;

    return 0;
}
