/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: climbing-stairs.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-24-2014 14:37:30
 * @version $Revision$
 *
 **************************************************************************/

#include <vector> 

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;

        v.assign({1, 1});
        v.resize(n+1);
        for (auto i = 2; i <= n; ++i) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
};

int main() {
    return 0;
}

