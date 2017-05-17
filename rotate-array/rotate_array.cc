/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: rotate_array.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 20:22:46
 * @version $Revision$
 *
 **************************************************************************/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size()) k = k % nums.size();

        std::rotate(nums.begin(), nums.begin()+(nums.size()-k), nums.end());
    }
};
