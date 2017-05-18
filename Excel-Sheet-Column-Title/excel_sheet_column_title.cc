/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: excel_sheet_column_title.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 21:21:48
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

class Solution {
    public:
        string convertToTitle(int n) {
            string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            string res;

            while (n) {

                if (n%26 == 0) {
                    res.insert(0, 1, 'Z');
                    if (n == 26) break;
                    n -= 26;
                }
                else res.insert(0, 1, s[n%26-1]);

                n /= 26;
            }
            return res;
        }
};

int main() {
    Solution s;

    cout << s.convertToTitle(27) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(10000) << endl;
    cout << s.convertToTitle(100) << endl;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(702) << endl;
    cout << s.convertToTitle(52) << endl;

    return 0;
}
