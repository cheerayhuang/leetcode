/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: non_decreasing_array.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-30-2017 22:15:34
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Check(vector<int>& nums) {
        for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (iter+1 != nums.end()) {
                if (*iter > *(iter+1)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool checkPossibility(vector<int>& nums) {
        auto wrong_order = 0;
        auto pos = 0;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (iter+1 != nums.end()) {
                if (*iter > *(iter+1)) {
                    wrong_order++;
                    if (wrong_order == 1) {
                        pos = iter - nums.begin();
                        break;
                    }
                }
            }
        }

        if (wrong_order == 0) return true;

        auto nums1 = nums;
        auto nums2 = nums;

        nums1[pos] = nums1[pos+1];
        nums2[pos+1] = nums2[pos];

        return (Check(nums1) || Check(nums2));
    }
};


int main() {
    Solution s;

    vector<int> v{3};
    cout << s.checkPossibility(v) << endl;

    return 0;
}
