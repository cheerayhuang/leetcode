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
#include <fstream>
#include <sys/time.h>

using namespace std; 

class Solution {
public:
    int strStr(const char *haystack, const char *needle) {
        if (haystack == nullptr || needle == nullptr) {
            return -1;
        }

        string str(haystack); 
        string substr(needle);
        auto len_str = str.size();
        auto len_substr = substr.size();

        if (len_str < len_substr) {
            return -1;
        }

        if (len_substr == 0) {
            return 0;
        }

        vector<int> back_trace(len_substr, -1);
        auto len_back_trace = back_trace.size();
        for (int beg = 1; beg < len_back_trace; ++beg) {
            int j = beg - 1;
            while (j != -1 && substr[beg] != substr[back_trace[j]+1]) {
                j = back_trace[j];
            }

            if (j != -1) {
                back_trace[beg] = back_trace[j]+1;
            }
        }
    
        auto beg_substr = 0;
        for (int beg = 0; beg < len_str; ++beg) {
            if (substr[beg_substr] == str[beg]) {
                ++beg_substr;
                if (beg_substr == len_substr) {
                    return beg - len_substr + 1;
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

    string str; 
    string substr;

    ifstream fin("./1.txt");

    timeval start, end;

    gettimeofday(&start, nullptr);

    while(fin >> str >> substr) {
        cout << s.strStr(str.c_str(), substr.c_str()) << endl;
    }

    gettimeofday(&end, nullptr);

    cout << (end.tv_sec-start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec << endl; 
    fin.close();

    return 0;
}


