/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: add-binary.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-24-2014 14:50:44
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <algorithm>
#include <string>

using namespace std; 

class Solution {
public:
    string addBinary(string a, string b) {
        if (b.empty()) {
            return a;
        }

        if (a.empty()) {
            return b;
        }

        if (a.size() < b.size()) {
            swap(a,b);
        }

        auto a_crbeg = a.crbegin();
        auto b_crbeg = b.crbegin();
        auto remainder = 0;
        string res_str; 

        while (a_crbeg != a.crend()) {
            int res  = *a_crbeg - 48;

            if (b_crbeg != b.crend()) {
                res += *b_crbeg - 48;
                ++b_crbeg;
            }
            res += remainder; 
            remainder = res / 2;
            res %= 2;

            res_str.push_back(res+48);
            ++a_crbeg;
        }

        if (remainder) {
            res_str.push_back(49);
        }

        return string(res_str.rbegin(), res_str.rend());
    }
};

int main() {
    Solution s; 

    cout << s.addBinary("110", "101") << endl;
    cout << s.addBinary("1", "0") << endl;
    cout << s.addBinary("0", "0") << endl;
    cout << s.addBinary("0", "1") << endl;
    cout << s.addBinary("1", "1") << endl;
    cout << s.addBinary("1111", "1") << endl;
    cout << s.addBinary("10", "11111") << endl;
    cout << s.addBinary("", "1111") << endl;
    cout << s.addBinary("1", "11") << endl;

    return 0;
}

