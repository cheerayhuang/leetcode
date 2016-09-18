/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: binary_watch.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-18-2016 11:03:24
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    pair<vector<short>, int> CountDigit1_(int m) {
        auto total = 0;
        vector<short> v(10, 0);

        auto beg = v.begin();
        while(m > 0) {
            if (m % 2 == 1) {
                ++total;
                *beg = 1;
            }
            m /= 2;
            ++beg;
        }

        return make_pair(std::move(v), total);
    }

    string ReadWatch_(vector<short> v) {

        auto min = 0;
        auto hour = 0;
        auto exp = 1;
        for_each(v.begin(), v.begin()+6, [&](short i) { min += i * exp; exp *= 2;});
        if (min > 59) return string();

        exp = 1;
        for_each(v.begin()+6, v.end(), [&](short i) { hour += i * exp; exp *= 2;});
        if (hour > 11) return string();

        string result = to_string(hour) + ":";
        if (min < 10) {
            result += "0";
        }
        result += to_string(min);

        return result;
    }

public:
    vector<string> readBinaryWatch(int num) {

        vector<string> num_list;
        for (auto i = 0; i <= 1023; ++i) {
            auto res = CountDigit1_(i);
            if (res.second == num) {
                auto tmp_str = ReadWatch_(res.first);
                if (!tmp_str.empty()) num_list.push_back(tmp_str);
            }
        }

        return std::move(num_list);
    }
};

int main() {
    Solution s;

    auto res = s.readBinaryWatch(0);

    for_each(res.begin(), res.end(), [](string s) { cout << s << endl;});

    return 0;
}

