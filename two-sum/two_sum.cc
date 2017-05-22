/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: two_sum.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-22-2017 11:40:02
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_times;
        for (auto i : nums) {
            num_times[i]++;
        }

        vector<int> res;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            auto j = target - *i;

            num_times[*i]--;
            if (num_times[j] > 0) {
                res.push_back(i-nums.begin());
                auto j_iter = find(i+1, nums.end(), j);
                res.push_back(j_iter-nums.begin());
                break;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}


