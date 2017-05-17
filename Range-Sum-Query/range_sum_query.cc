/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: range_sum_query.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 16:07:41
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> s;
    vector<int> n;
public:
    NumArray(vector<int> nums) {
        n = nums;
        auto prior = 0;
        for (auto i : nums) {
            s.push_back(i+prior);
            prior = i+prior;
        }

    }

    int sumRange(int i, int j) {
        return s[j]-s[i] + n[i];
    }
};


int main() {

    vector<int> v{-2, 0, 3, -5, 2, -1};
    NumArray obj(v);
    cout << obj.sumRange(0,2) << endl;
    cout << obj.sumRange(2,5) << endl;
    cout << obj.sumRange(0,5) << endl;

    return 0;
}

