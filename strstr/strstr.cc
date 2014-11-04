/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: strstr.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 18:05:44
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

class Solution {
public:
    int strStr(const char *haystack, const char *needle) {
        if (haystack == nullptr || needle == nullptr) {
            return -1;
        }

        string str(haystack); 
        string substr(needle);
        if (str.size() < substr.size()) {
            return -1;
        }

        auto pos = str.find(substr); 
        if (pos == string::npos) {
            return -1;
        }
        return pos;
    }
};

int main() {
    Solution s;

    cout << s.strStr("hello" ,"ll") << endl;

    return 0;
}


