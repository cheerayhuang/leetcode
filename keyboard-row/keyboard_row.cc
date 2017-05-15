/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: keyboard_row.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-15-2017 20:07:28
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyborad {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> res;

        for (auto s : words) {
            auto line = -1;
            auto is_in_line = true;
            for (auto c : s) {
                auto letter = c;
                if (c < 97) {
                    letter += 32;
                }
                for (int i = 0; i < 3; ++i) {
                    if (keyborad[i].find(letter) != string::npos) {
                        if (line == -1) {
                            line = i;
                            break;
                        } else {
                            if (line != i) is_in_line = false;
                            break;
                        }
                    }
                }
                if (!is_in_line) break;
            }
            if (is_in_line) {
                res.push_back(s);
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<string> words {"Hello", "Alaska", "Dad", "Peace"};
    auto res = s.findWords(words);

    ostream_iterator<string> out_iter(cout, " ");
    for (auto s : res ) {
        out_iter = s;
    }

    return 0;
}

