/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: next-greater-element-1.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-16-2017 20:46:53
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for (auto i : findNums) {
            auto pos = find(nums.begin(), nums.end(), i);
            auto pos_nums = find_if(pos, nums.end(), [i](int j) { return j > i;});

            if (pos_nums != nums.end()) {
                res.push_back(*pos_nums);
            } else {
                res.push_back(-1);
            }

        }

        return res;
    }
};

int main() {

    vector<int> vec1 {2, 3, 1};
    vector<int> vec2 {3, 2, 1, 4};

    Solution s;

    auto res = s.nextGreaterElement(vec1, vec2);

    for(auto i : res) {
        cout << i << endl;
    }

    return 0;
}

