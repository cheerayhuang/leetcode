/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: array-partition.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-11-2017 11:17:49
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                res += nums.at(i);
            }
        }

        return res;
    }
};

int main() {

    Solution s;

    vector<int> v {1, 2, 3, 4};
    cout << s.arrayPairSum(v) << endl;

    return 0;
}
