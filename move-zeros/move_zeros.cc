/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: move_zeros.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 12:40:12
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto i = nums.begin();
        auto j = nums.begin();

        while(j != nums.end()) {
            if (*j != 0) {
                swap(*i, *j);
                ++i;
            }
            ++j;
        }
    }
};


int main() {

    vector<int> vec{1, 2};

    Solution s;
    s.moveZeroes(vec);

    ostream_iterator<int> cout_iter(cout);

    copy(vec.begin(), vec.end(), cout_iter);

    return 0;

}
