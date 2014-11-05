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
#include <fstream>
#include <sys/time.h>

using namespace std; 

//struct timeval {
//    time_t      tv_sec;     /* seconds */
//    suseconds_t tv_usec;    /* microseconds */
//}; 

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


