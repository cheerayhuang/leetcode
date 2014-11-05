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
#include <vector>

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

        vector<int> back_trace(substr.size(), -1);
        for (int beg = 1; beg < back_trace.size(); ++beg) {
            int j = beg - 1;
            while (j != -1 && substr[beg] != substr[back_trace[j]+1]) {
                j = back_trace[j];
            }

            if (j != -1) {
                back_trace[beg] = back_trace[j]+1;
            }
        }
    
        auto beg_substr = 0;
        for (int beg = 0; beg < str.size(); ++beg) {
            if (substr[beg_substr] == str[beg]) {
                ++beg_substr;
                if (beg_substr == substr.size()) {
                    return beg - substr.size() + 1;
                }
            } else {
                if (beg_substr != 0) {
                    --beg;
                    beg_substr = back_trace[beg_substr-1] + 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;

    cout << s.strStr("Hellow", "ll") << endl;
    cout << s.strStr("aaaaaaaaaaaab", "aaaab") << endl;

    return 0;
}


