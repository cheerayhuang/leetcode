/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: zigzag-conversion.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 15:50:11
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>
#include <string>

using namespace std; 

class Solution {

public:
    string convert(string s, int n) {
        if (n == 1) {
            return s;
        }

        if (n == 0) {
            return string();
        }
        vector<string> v(n);

        vector<int> director {1, -1};
        auto cur_director = 0;

        auto cur_x = 0;

        for(auto i = 0; i < s.size(); ++i) {
            v[cur_x].append(1, s[i]);    

            auto next_x = cur_x + director[cur_director];

            if (next_x >= n || next_x < 0) {
                cur_director = (cur_director+1) % 2;
                cur_x += director[cur_director];
            }
            else {
                cur_x = next_x;
            }
        }
        
        string res; 
        for (auto i = 0; i < n; ++i) {
            res += v[i];
        }

        return res;
    }
};

int main() {
    Solution s; 
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("ABCD", 4) << endl;
    cout << s.convert("A", 1000) << endl;
    cout << s.convert("", 1) << endl;
    cout << s.convert("AB", 1) << endl;
    cout << s.convert("AB", 0) << endl;

    return 0;
}

