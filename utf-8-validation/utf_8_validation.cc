/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: utf_8_validation.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 20:37:09
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iterator>

using namespace std;

class Solution {

private:
    vector<string> Transform2Bin_(const vector<int>& data) {
        vector<string> res;
        for (auto i : data) {
            string tmp_str;
            while (i != 0 && tmp_str.size() < 8) {
                auto k = i % 2;
                i /= 2;
                tmp_str.insert(0, to_string(k));
            }
            if (tmp_str.length() < 8) {
                tmp_str.insert(0, 8-tmp_str.length(), '0');
            }
            res.push_back(tmp_str);
        }

        return std::move(res);
    }

public:
    bool validUtf8(vector<int>& data) {

        auto res = Transform2Bin_(data);

        auto iter = res.begin();
        auto len_next_bytes = 0;
        while (iter != res.end()) {

            if (len_next_bytes > 0) {
                if (iter->find("10") != 0) return false;
                --len_next_bytes;
                ++iter;
                continue;
            }

            if (iter->find('0') == 0) {
                ++iter;
                continue;
            }

            auto s = *iter;
            for (auto ch : s) {
                if (ch == '1') ++len_next_bytes;
                else break;
            }
            if (len_next_bytes == 1) return false;
            --len_next_bytes;
            ++iter;
        }

        if (len_next_bytes > 0 ) return false;

        return true;
    }
};

int main() {

    Solution s;

    vector<int> vec{197, 130, 1};

    cout << s.validUtf8(vec) << endl;

    vec.assign({145, 1});
    cout << s.validUtf8(vec) << endl;


    return 0;
}

