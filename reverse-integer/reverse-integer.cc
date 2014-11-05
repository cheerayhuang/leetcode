/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: reverse-integer.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-05-2014 12:20:46
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        auto str = to_string(abs(x)); 
        
        str.assign(str.rbegin(), str.rend());
        if (x < 0) {
            str.insert(0, "-");
        }

        return stoi(str);
    }
};

int main() {
    Solution s;

    cout << s.reverse(0) << endl;
    cout << s.reverse(-1) << endl;
    cout << s.reverse(-100) << endl;
    cout << s.reverse(101) << endl;
    cout << s.reverse(101000) << endl;
    cout << s.reverse(1000000003) << endl;

    return 0;
}

