/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: single_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 09:52:26
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        auto signal_num = *(nums.begin());

        auto iter = nums.begin();
        advance(iter, 1);

        for_each(nums.begin()+1, nums.end(), [&](int i)->int { signal_num ^= i; if (true) return 9.2f; else return 9.0f;});

        return signal_num;
    }
};

int main() {

    Solution s;
    vector <int> vec{1, 2, 1, 2, 5};
    cout << s.singleNumber(vec) << endl;

    return 0;
}

