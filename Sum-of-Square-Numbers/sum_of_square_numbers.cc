/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: sum_of_square_numbers.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-02-2017 09:39:14
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {

        for (auto i = 0; i*i <= c/2; ++i) {
           auto rest = c - i*i;
           auto j = static_cast<int>(sqrt(rest));
           if (j*j == rest) {
               cout << j << endl;
               return true;
           }
        }

        return false;
    }
};

int main() {
    Solution s;

    cout << s.judgeSquareSum(5) << endl;
    cout << s.judgeSquareSum(9) << endl;
    cout << s.judgeSquareSum(3) << endl;
    cout << s.judgeSquareSum(2) << endl;
    cout << s.judgeSquareSum(10000) << endl;
    cout << s.judgeSquareSum(1000) << endl;

    return 0;
}


