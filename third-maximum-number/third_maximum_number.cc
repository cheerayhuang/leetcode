/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: third_maximum_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 17:53:48
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max = *min_element(nums.begin(), nums.end());
        int second_max = max;
        int third_max = max;

        for(auto i : nums) {
            if (i > max) max =i;
        }

        for (auto i : nums) {
            if (i > second_max && i != max) second_max = i;
        }

        for (auto i : nums) {
            if (i > third_max && i != max && i != second_max) third_max = i;
        }

        if (third_max != second_max && third_max != max) return third_max;

        return max;
    }
};

int main() {
    Solution s;

    vector<int> v1 {3, 2, 1};
    cout << s.thirdMax(v1) << endl;

    v1.assign({3, 2});
    cout << s.thirdMax(v1) << endl;

    v1.assign({3, 2, 2, 1});
    cout << s.thirdMax(v1) << endl;

    v1.assign({1, 1, 2, 1});
    cout << s.thirdMax(v1) << endl;


    v1.assign({1, 1, 1, 1});
    cout << s.thirdMax(v1) << endl;


    v1.assign({1, 2, 2, 5, 3, 5});
    cout << s.thirdMax(v1) << endl;

    return 0;

}

