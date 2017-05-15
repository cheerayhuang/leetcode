/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: complement_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-15-2017 19:22:45
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }

        auto n = 0;
        auto r = 0;
        while (num) {
            if (num % 2 == 0) {
                r += 1 << n;
            }
            num /= 2;
            ++n;
        }

        return r;
    }
};

int main() {

    Solution s;

    cout << s.findComplement(5) << endl;
    cout << s.findComplement(1) << endl;
    cout << s.findComplement(7) << endl;
    cout << s.findComplement(0) << endl;
    cout << s.findComplement(8) << endl;

    return 0;
}
