/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: compare-version-numbers.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 12-16-2014 12:43:26
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t posA = version1.find('.', 0);
        size_t posB = version2.find('.', 0);
        size_t begA = 0; 
        size_t begB = 0;
        do {
            auto verA = 0;
            auto verB = 0;
            if (begA != version1.length()) {
                verA = stoi(version1.substr(begA, posA-begA));
            } 
            if (begB != version2.length()) {
                verB = stoi(version2.substr(begB, posB-begB));
            }
            if (verA > verB) {
                return 1;
            }
            else if (verA < verB) {
                return -1;
            }

            if (posA != string::npos) {
                begA = posA + 1;
                posA = version1.find('.', begA);
            }
            else {
                begA = version1.length();
            }
            if (posB != string::npos) {
                begB = posB + 1;
                posB = version2.find('.', begB);
            }
            else {
                begB = version2.length();
            }
        } while (begA !=  version1.length() || begB != version2.length());

        return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.1.1", "1.1") << endl;
    cout << s.compareVersion("2.1", "3.1") << endl;
    cout << s.compareVersion("3", "3.0") << endl;
    cout << s.compareVersion("3", "3.0.0.0.0") << endl;
    cout << s.compareVersion("3", "3.0.0.0.1") << endl;
    cout << s.compareVersion("01", "1") << endl;

    return 0;
}

