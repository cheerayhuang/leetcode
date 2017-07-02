/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: happy_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-01-2017 16:27:53
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {

int ComputeDigitsSquareSum(int n) {
    auto sum = 0;
    while(n != 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}

public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (true) {
            n = ComputeDigitsSquareSum(n);
            if (n == 1) return true;

            if (s.count(n)) return false;

            s.insert(n);
        }
    }
};

int main() {
    Solution s;

    cout << s.isHappy(7) << endl;
    return 0;
}

