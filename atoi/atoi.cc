/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: atoi.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-05-2014 15:39:48
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        string s(str); 

        auto p = s.find_first_of("0123456789");
        if (p == string::npos) {
            return 0;
        }
    
        auto i = 0;
        while(p != 0 && (s[p-1] == '-' || s[p-1] == '+')) {
            --p;
            ++i;
        }
        if (i > 1) {
            return 0;
        }

        auto p_end = s.find_first_not_of("0123456789", p+1);
        if (p_end == string::npos) {
            p_end = s.size();
        }

        auto tmp = s.substr(p, p_end-p); 
        string str_int_max;
        if (tmp[0] == '-') {
            str_int_max.assign(to_string(INT_MIN));
        }
        else {
            str_int_max.assign(to_string(INT_MAX));
            if (tmp[0] == '+') {
                str_int_max.insert(str_int_max.begin(), '+');
            }
        }

        if (tmp.size() > str_int_max.size() || (tmp.size() == str_int_max.size() && tmp.compare(str_int_max) > 0)) {
            return stoi(str_int_max);    
        }
        
        return stoi(s.substr(p, p_end-p));
    }
};

int main() {
    Solution s;

    cout << s.atoi("+-abcedf-1234abcddfdf") << endl;
    cout << stoi("-1234      abcdef") << endl;
    cout << stoi("2000000000") << endl;
    cout << s.atoi("134000000000") << endl;
    cout << s.atoi("abcd01-0-2147483646") << endl;
    cout << s.atoi("+-2") << endl;
    cout << s.atoi("--2147483648") << endl;
    cout << s.atoi("-2147483648") << endl;
    cout << s.atoi("-2147483649") << endl;
    cout << s.atoi("++2147483649") << endl;

    return 0;
}

