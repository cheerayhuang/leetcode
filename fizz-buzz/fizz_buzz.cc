/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: fizz_buzz.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-15-2017 20:34:55
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for (auto i = 1; i <= n; ++i) {
            auto s = string();
            if (i % 3 == 0)
                s += "Fizz";
            if (i % 5 == 0)
                s += "Buzz";

            if (s.empty()) {
                s = std::to_string(i);
            }

            res.push_back(s);
        }

        return res;
    }
};


int main() {

    Solution s;

    auto res = s.fizzBuzz(15);

    for_each(res.begin(), res.end(), [](string& s) {cout << s << endl;});

    return 0;
}
