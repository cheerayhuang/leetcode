/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: count-and-say.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-05-2014 11:41:11
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) {
            return string();
        }
        
        vector<string> v{"1", "11", "21", "1211", "111221"}; 
        v.reserve(n+1);
        v.resize(n);

        for(auto i = 5; i < n; ++i) {
            auto init_pos = 0;
            while(init_pos < v[i-1].size()) {
                auto init_char = v[i-1][init_pos];
                auto p = v[i-1].find_first_not_of(init_char, init_pos);
                if (p == string::npos) {
                    p = v[i-1].size();
                }
                v[i].append(string{static_cast<char>(p-init_pos + 48), init_char}); 
                init_pos = p;
            }
        }

        return v[n-1];
    }
};

int main() {
    
    Solution s; 

    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(0) << endl;
    cout << s.countAndSay(7) << endl;
    cout << s.countAndSay(8) << endl;

    return 0;
}

