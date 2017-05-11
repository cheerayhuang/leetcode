/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: reshape_the_matrix.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-11-2017 20:49:09
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

void Print(const vector<vector<int>>& v);

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        auto ori_r = nums.size();
        auto ori_c = nums.at(0).size();

        if (r*c != ori_r*ori_c) {
            return nums;
        }

        vector<int> data;
        for (auto v : nums) {
            for (auto i : v) {
                data.push_back(i);
            }
        }

        vector<vector<int>> res(r);
        auto i = 0;

        for (auto k = 0; k < r; ++k) {
            for (auto j = 0; j < c; ++j, ++i)
                res.at(k).push_back(data.at(i));
        }

        return res;
    }
};

void Print(const vector<vector<int>>& v) {
    for_each(v.begin(), v.end(),
        [](vector<int> c) {
            for(auto i : c) {
                cout << i << ' ';
            }
            cout << endl;
        }
    );
}

int main() {

    Solution s;

    vector<vector<int>> d{{1,2}, {3,4}};

    auto r = s.matrixReshape(d, 1, 4);
    Print(r);

    r = s.matrixReshape(d, 2, 4);
    Print(r);

    r = s.matrixReshape(d, 4, 1);
    Print(r);

    return 0;
}

