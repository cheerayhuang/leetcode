/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: roman-to-integer.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-24-2014 15:24:35
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <unordered_map> 

using namespace std; 

class Solution {
private:
    unordered_map<char, int> roman_ = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(string s) {
        int res = 0;
        auto i = 0;
        while (i < s.size()) {
            if (i+1 >= s.size() || roman_[s[i+1]] <= roman_[s[i]]) {
                res += roman_[s[i]];                
            }
            else {
                res -= roman_[s[i]];
            }

            ++i;
        }

        return res;
    }
};

int main() {
    Solution s; 
    cout << s.romanToInt("XIV") << endl;
    cout << s.romanToInt("XCIX") << endl;
    cout << s.romanToInt("XL") << endl;
    cout << s.romanToInt("XCIII") << endl;

    return 0;
}

