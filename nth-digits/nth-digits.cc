/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: nth-digits.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 11:06:27
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

        auto len_digits = i;
        while(len_digits-- > 1) {
            beg = beg * 10;

        }

        beg += (n-1) / i;
        return to_string(beg)[(n-1) % i] - 48;
    }
};

int main() {
    return 0;
}

