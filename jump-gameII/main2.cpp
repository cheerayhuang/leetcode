/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: main2.cpp
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-20-2018 13:36:11
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    int jump(vector<int>&& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return 1;
        if (nums[0] >= nums.size()-1) return 1;

        auto l = nums.size() -1;
        auto total = 0;
        while(l != 0) {
            auto i = 0;
            for (; i < l; i++) {
                if (nums[i] + i >= l) break;
            }

            l  = i;
            total++;
        }

        return total;
    }
};

int main() {
    Solution s;
    cout << s.jump(vector<int>{2, 3, 1, 1, 4}) << endl;

    return 0;
}
