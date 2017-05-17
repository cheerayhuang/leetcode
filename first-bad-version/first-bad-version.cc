/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: first-bad-version.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-17-2017 20:41:18
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <cstdint>

using namespace std;

bool isBadVersion(int n) {
    return n >= 1702766719;
}

class Solution {
    public:
        int firstBadVersion(int n) {
            unsigned int begin = 0;
            unsigned int end = n;

            while(end-begin > 1) {
                unsigned int mid = (begin + end) / 2;
                if (isBadVersion(mid)) {
                    end = mid;

                } else {
                    begin = mid;
                }
                cout << begin << ' ' << end << endl;
            }

            if (isBadVersion(begin)) return begin;

            return end;
        }
};

int main() {
    Solution s;

    cout << s.firstBadVersion(2126753390) << endl;

    return 0;
}
