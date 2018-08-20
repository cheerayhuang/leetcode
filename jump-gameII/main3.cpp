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

        auto total = 1;

        int init_oil = nums[0];
        int max_d = 0;
        int max_pos = 0;

        for (auto i = 1; i < nums.size(); ++i) {
            init_oil--;
            if (i + nums[i] > max_d) {
                max_d = i+nums[i];
                max_pos = i;
            }

            if (init_oil == 0 && i != nums.size()-1) {
                total++;
                init_oil = nums[max_pos] - (i - max_pos);
            }
        }

        return total;
    }
};

int main() {
    Solution s;
    cout << s.jump(vector<int>{2, 3, 1, 1, 4}) << endl;
    cout << s.jump(vector<int>{2, 6, 2, 1, 4, 1}) << endl;
    cout << s.jump(vector<int>{1,1,1, 1,1}) << endl;

    return 0;
}
