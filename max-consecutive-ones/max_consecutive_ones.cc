/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: max_consecutive_ones.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-16-2017 22:12:37
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class Solution {
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int max = 0;
        for (auto i : nums) {
            if (i) res += i;
            else res *= i;
            if (res > max) max = res;
        }

        return max;
    }
};

int main() {
    return 0;
}


