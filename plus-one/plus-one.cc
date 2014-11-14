/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: plus-one.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-11-2014 16:42:25
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std; 

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        auto riter = digits.rbegin(); 
        (*riter)++; 
        auto remainder = *riter / 10;
        *riter %= 10;

        riter++;
        for(; riter != digits.rend(); ++riter) {
            if (remainder == 0) break;
            *riter += remainder;
            remainder = *riter / 10;
            *riter %= 10;
        }

        if (remainder != 0) {
            digits.insert(digits.begin(), remainder);
        }

        return digits;

    }
};

int main() {
    Solution s;

    ostream_iterator<int> os_iter(cout, " ");

    vector<int> v{0};
    vector<int> v1{9}; 
    vector<int> v2{9, 9, 9, 9, 9};

    auto res = s.plusOne(v); 
    for_each(res.begin(), res.end(), [](int i) { cout << i << " "; });
    cout << endl;

    res = s.plusOne(v1);
    copy(res.begin(), res.end(), os_iter);
    cout << endl;

    res = s.plusOne(v2);
    copy(res.begin(), res.end(), os_iter);
    cout << endl;

    return 0;
}

