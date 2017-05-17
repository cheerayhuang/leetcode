/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: k_diff_pairs_in_an_array.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 16:38:39
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // import!, k < 0 , return 0
        if (k < 0) return 0;
        auto res = 0;
        unordered_multiset<int> s;

        sort(nums.begin(), nums.end());
        for (auto i : nums) s.insert(i);
        auto e = unique(nums.begin(), nums.end());
        nums.resize(e-nums.begin());

        for (auto i : nums) {
            if (k != 0) {
                if (s.count(i+k))  res++;
            } else if (s.count(i) > 1) {
                res++;
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> v1{1, 2, 3, 4, 5, 1};
    cout << s.findPairs(v1, 0) << endl;
    for_each(v1.begin(), v1.end(), [](int i) { cout << i << ' '; });
    cout << endl;
    vector<int> v2{1, 2, 3, 4, 5, 1};
    cout << s.findPairs(v2, 1) << endl;

    return 0;
}
