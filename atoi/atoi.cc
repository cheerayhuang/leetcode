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

        auto beg = s.find_first_of("+-0123456789");
        if (beg == string::npos || beg != s.find_first_not_of(' ')) {
            return 0;
        }

        size_t end;
        if (s[beg] == '-' || s[beg] == '+') {
            end = s.find_first_not_of("0123456789", beg+1);
            if (end == beg+1) {
                return 0;
            }
        }
        else {
            end = s.find_first_not_of("0123456789", beg);
        }

        if (end == string::npos) {
            end = s.size();
        }

        auto tmp = s.substr(beg, end-beg);

        string int_limit; 
        if (tmp[0] == '-') {
            int_limit = to_string(INT_MIN);    
        }
        else {
            int_limit = to_string(INT_MAX);
            if (tmp[0] == '+') {
                int_limit.insert(int_limit.begin(), '+');
            }
        }

        if (tmp.size() > int_limit.size() || (tmp.size() == int_limit.size() && tmp.compare(int_limit) > 0)) {
            return stoi(int_limit);
        }

        return stoi(tmp);
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

