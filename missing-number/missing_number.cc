/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: missing_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 06-22-2017 20:33:04
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto cur = 0;

        sort(nums.begin(), nums.end());
        for (auto i : nums) {
            if (cur != i) return cur;
            ++cur;
        }
    }
};

int main() {
    return 0;
}
