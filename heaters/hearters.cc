/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: heaters.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 11:20:14
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        if (houses == heaters) return 0;
        if (search(heaters.begin(), heaters.end(), houses.begin(), houses.end()) != heaters.end()) return 0;

        vector<int>new_houses;
        unordered_set<int> heaters_pos;
        for (auto h : heaters) heaters_pos.insert(h);
        for (auto h : houses) if (!heaters_pos.count(h)) new_houses.push_back(h);

        vector<int> diff_vec;
        for (auto h : new_houses) {
            function<bool(int)> next_heater = bind([](int a, int b){ return b > a; }, h, placeholders::_1);
            function<bool(int)> prior_heater = bind([](int a, int b){ return b < a; }, h, placeholders::_1);
            auto n  = find_if(heaters.begin(), heaters.end(), next_heater);
            auto p = find_if(heaters.rbegin(), heaters.rend(), prior_heater);

            auto diff = INT_MAX;
            if (n != heaters.end()) {
                diff = *n - h;
            }

            if (p != heaters.rend() && (h - *p < diff)) {
                diff = h - *p;
            }

            diff_vec.push_back(diff);
        }

        return *max_element(diff_vec.begin(), diff_vec.end());
    }
};

int main() {

    vector<int> vec1{1,2,3,4};
    vector<int> vec2{1,4};
    Solution s;
    cout << s.findRadius(vec1, vec2) << endl;

    vec1.assign({1, 5, 8});
    vec2.assign({2, 7});
    cout << s.findRadius(vec1, vec2) << endl;

    vec1.assign({1, 2});
    vec2.assign({1, 2});
    cout << s.findRadius(vec1, vec2) << endl;

    vec1.assign({1, 2, 3});
    vec2.assign({3});
    cout << s.findRadius(vec1, vec2) << endl;

    vec1.assign({1, 2, 3});
    vec2.assign({1, 2, 3, 4});
    cout << s.findRadius(vec1, vec2) << endl;

    vec1.clear();
    vec2.clear();
    for (auto i = 1; i <= 25000; ++i) vec1.push_back(i);
    for (auto i = 2; i <= 25000; ++i) vec2.push_back(i);
    cout << s.findRadius(vec1, vec2) << endl;

    return 0;
}



