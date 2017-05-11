/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: distribute_candies.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-11-2017 13:10:52
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        auto uni_end = unique(candies.begin(), candies.end());
        auto num = uni_end - candies.begin();

        /*
        for_each(candies.begin(), uni_end, [](int i) { cout << i << ' ';});
        cout << endl;
        */

        if (num < candies.size() / 2)
            return num;

        return candies.size() / 2;
    }
};

int main() {

    Solution s;

    vector<int> v{1, 1, 2, 2, 3, 3};
    cout << s.distributeCandies(v) << endl;


    vector<int> v2{1, 2, 2, 3, 3, 4};
    cout << s.distributeCandies(v2) << endl;

    vector<int> v3{1, 1, 2, 3};
    cout << s.distributeCandies(v3) << endl;

    v3.assign({1,1});
    cout << s.distributeCandies(v3) << endl;

    v3.assign({1,2});
    cout << s.distributeCandies(v3) << endl;

    v3.assign({100000,0,100000,0,100000,0,100000,0,100000,0,100000,0});
    cout << s.distributeCandies(v3) << endl;


    return 0;
}

