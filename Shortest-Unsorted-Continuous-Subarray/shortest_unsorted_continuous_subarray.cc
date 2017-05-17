/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: shortest_unsorted_continuous_subarray.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 08:54:53
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>nums2(nums);

        sort(nums2.begin(), nums2.end());

        if (nums == nums2) { return 0; }

        auto iter_beg = mismatch(nums.begin(), nums.end(), nums2.begin());
        auto iter_end = mismatch(nums.rbegin(), nums.rend(), nums2.rbegin());


        return  iter_end.first.base() - iter_beg.first;
    }
};

int main() {
    Solution s;

    vector<int> vec1{1, 2, 4, 3};
    cout << s.findUnsortedSubarray(vec1) << endl;

    vec1.assign({2, 6, 4, 8, 10, 9, 15});
    cout << s.findUnsortedSubarray(vec1) << endl;

    vec1.assign({2, 6, 6, 10, 10, 9, 15});
    cout << s.findUnsortedSubarray(vec1) << endl;

    vec1.assign({2, 6, 6});
    cout << s.findUnsortedSubarray(vec1) << endl;

    vec1.assign({6, 6, 6});
    cout << s.findUnsortedSubarray(vec1) << endl;

    vec1.assign({6, 6, 6, 6, 1});
    cout << s.findUnsortedSubarray(vec1) << endl;

    vec1.assign({6, 5, 4, 3, 1});
    cout << s.findUnsortedSubarray(vec1) << endl;

    return 0;
}
