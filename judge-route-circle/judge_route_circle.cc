/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: judge_route_circle.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-30-2017 15:32:06
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> directions {
            {'U', make_pair(-1, 0)},
            {'D', make_pair(1, 0)},
            {'R', make_pair(0, 1)},
            {'L', make_pair(0, -1)}
        };

        auto x = 0;
        auto y = 0;

        for (auto ch : moves) {
            if (directions.count(ch) != 0) {
                x += directions[ch].first;
                y += directions[ch].second;
            }
        }

        if (x == 0 && y == 0) return true;

        return false;
    }
};

int main() {
    Solution s;

    cout << s.judgeCircle("UD") << endl;

    return 0;
}
