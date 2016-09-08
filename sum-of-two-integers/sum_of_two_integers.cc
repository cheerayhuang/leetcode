/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: sum_of_two_integers.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-07-2016 17:11:56
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        auto c = 0;
        auto sum = 0;
        do {
            sum = a ^ b;
            c = (a & b) << 1;
            a = sum;
            b = c;
        } while (c != 0);

        return sum;
    }
};


int main() {
    Solution s;

    cout << s.getSum(5, 5) << endl;
    cout << s.getSum(0, 0) << endl;
    cout << s.getSum(0, 1) << endl;
    cout << s.getSum(12345, 543219) << endl;

    return 0;
}

