/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: integer_replacement.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-11-2016 10:42:45
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> f_{0, 0, 1};

public:
    int integerReplacement(long n) {

        if (n == 0) return 0;

        auto pre_step = 0;

        while (n % 2 == 0) {
            ++pre_step;
            n /= 2;
        }

        if (n == 1) return pre_step;

        auto res1 = integerReplacement(n+1) + 1;
        auto res2 = integerReplacement(n-1) + 1;

        return ((res1 < res2) ? (res1 + pre_step) : (res2 + pre_step));
    }
};

int main() {
    Solution s;

    cout << s.integerReplacement(1) << endl;
    cout << s.integerReplacement(2) << endl;
    cout << s.integerReplacement(3) << endl;
    cout << s.integerReplacement(4) << endl;
    cout << s.integerReplacement(7) << endl;
    cout << s.integerReplacement(8) << endl;
    cout << s.integerReplacement(5000000) << endl;
    cout << s.integerReplacement(100000000) << endl;
    cout << s.integerReplacement(2147483647) << endl;

    return 0;
}
