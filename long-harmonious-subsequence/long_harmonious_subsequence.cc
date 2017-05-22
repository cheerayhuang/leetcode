/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: long_harmonious_subsequence.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-22-2017 16:29:08
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, pair<int, int>> m;
        map<int, bool> is_valid;

        for (auto i : nums) {
            if (is_valid.count(i) == 0) is_valid[i] = false;

            auto min_sub = 0;
            if (m.count(i+1)) { min_sub = m[i+1].second; is_valid[i] = true; }
            auto max_sub = 0;
            if (m.count(i-1)) { max_sub = m[i-1].first; is_valid[i] = true; }

            if (m.count(i)) {
                if (min_sub < m[i].first) min_sub = m[i].first;
                if (max_sub < m[i].second) max_sub = m[i].second;
            }

            m[i] = make_pair(min_sub+1, max_sub+1);
        }

        auto max_lhs = 0;
        for (auto i : m) {
            auto j = ::max(i.second.first, i.second.second);
            if (j > max_lhs && is_valid[i.first]) {
                max_lhs = j;
            }
        }

        return max_lhs;
    }
};


int main() {
    vector<int> v{1,3,2,2,5,2,3,7};

    Solution s;
    cout << s.findLHS(v) << endl;

    v.assign({1,1,1,1,2,2});
    cout << s.findLHS(v) << endl;

    v.assign({3,4,5});
    cout << s.findLHS(v) << endl;

    v.assign({});
    cout << s.findLHS(v) << endl;

    v.assign({1,1,1,1});
    cout << s.findLHS(v) << endl;

    v.assign({1});
    cout << s.findLHS(v) << endl;

    v.assign({2,2,1,1});
    cout << s.findLHS(v) << endl;

    v.assign({1,4,1,3,1});
    cout << s.findLHS(v) << endl;

    v.assign({1,4,1,3,1,-14,1,-13});
    cout << s.findLHS(v) << endl;

    v.assign({0, 0, 0, 0, -5, -6, -7});
    cout << s.findLHS(v) << endl;

    v.assign({0, 0, 0, 0, -5, -5, -7});
    cout << s.findLHS(v) << endl;

    v.assign({-5,-5});
    cout << s.findLHS(v) << endl;

    v.clear();
    mt19937 mt_gen((random_device())());
    for (auto i = 0; i < 20000; ++i) {
        v.push_back(mt_gen() % 50);
    }
    cout << s.findLHS(v) << endl;

    return 0;
}
