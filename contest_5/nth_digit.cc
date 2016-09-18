/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: nth_digit.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-18-2016 09:51:40
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(long n) {
        if (n == 0) return 0;

        long exp = 1;
        long i = 1;

        while (n - i*9*exp > 0) {
            n -= i * 9 * exp;
            exp *= 10;
            ++i;
        }

        long beg = 1;
        //long end = 9;
        auto len_digits = i;
        while(len_digits-- > 1) {
            beg = beg * 10;
            //end = end * 10 + 9;
        }

        beg += (n-1) / i;
        return to_string(beg)[(n-1) % i] - 48;
    }
};

int main() {
    Solution s;

    cout << s.findNthDigit(11) << endl;
    cout << s.findNthDigit(10) << endl;
    cout << s.findNthDigit(3) << endl;
    cout << s.findNthDigit(1) << endl;
    cout << s.findNthDigit(9) << endl;
    cout << s.findNthDigit(0) << endl;
    cout << s.findNthDigit(190) << endl;
    cout << s.findNthDigit(191) << endl;
    cout << s.findNthDigit(2147483648) << endl;

    return 0;
}

