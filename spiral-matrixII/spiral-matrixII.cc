/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: spiral-matrixII.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-03-2014 11:15:26
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector> 

using namespace std; 

class Solution {
private:
    const vector<pair<int, int>> directors_ = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int director_;

    vector<vector<int> > result_;
    
public:
    vector<vector<int> > generateMatrix(int n) {
        director_ = 0; 
        auto cur_x = 0; 
        auto cur_y = 0;
        result_.assign(n, vector<int>(n, 0));

        for (auto i = 1; i <= n*n; ++i) {
            result_[cur_x][cur_y] = i;
            auto next_x = cur_x + directors_[director_].first;
            auto next_y = cur_y + directors_[director_].second;
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || result_[next_x][next_y]) {
                director_ = (director_ + 1) % 4;
                cur_x += directors_[director_].first;
                cur_y += directors_[director_].second; 
            } else {
                cur_x = next_x;
                cur_y = next_y;
            }
        }

        return result_;
    }
};

int main() {
    Solution s;
    auto res = s.generateMatrix(4);

    for (auto &i : res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    res = s.generateMatrix(0);

    for (auto &i : res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

