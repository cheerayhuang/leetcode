/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: hamming_distance.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-11-2017 10:24:19
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        auto m = x ^ y;
        auto res = 0;
        while (m) {
            res += (m % 2);
            m /= 2;
        }

        return res;
    }
};

int main() {

    Solution s;

    cout << s.hammingDistance(1, 4) << endl;

    return 0;
}

