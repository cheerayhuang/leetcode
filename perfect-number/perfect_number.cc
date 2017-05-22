/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: perfect_number.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-22-2017 10:52:15
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
    public:
        bool checkPerfectNumber(int num) {
            const vector<unsigned long> prime{2, 3, 5, 7, 11, 13, 17};
            set<long long> perfect_num;

            for (auto i : prime) {
                //cout << (1<<static_cast<long>(i-1)) * (static_cast<long>(1<<i)-1) << endl;
                perfect_num.insert((1<<(i-1))*((1<<i)-1));
            }

            /*for (auto i = perfect_num.begin(); i != perfect_num.end(); ++i) {
                cout << *i << endl;
            }*/

            if (perfect_num.count(num)) return true;

            cout << sizeof(long) << endl;
            cout << sizeof(int) << endl;

            return false;
        }
};

int main() {
    Solution s;

    s.checkPerfectNumber(28);

    return 0;
}
