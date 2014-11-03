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

    vector<int> result_;

    
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        director_ = 0; 
        auto cur_x = 0; 
        auto cur_y = 0;
        auto n = matrix.size();
        result_.clear();

        for (auto i = 1; i <= n*n; ++i) {
            result_.push_back(matrix[cur_x][cur_y]);
            matrix[cur_x][cur_y] = 0;
            auto next_x = cur_x + directors_[director_].first;
            auto next_y = cur_y + directors_[director_].second;
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || matrix[next_x][next_y] == 0) {
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

    vector<vector<int> > m { 
        {1, 2, 3, 4, 5}, 
        {6, 7, 8, 9, 10}, 
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    Solution s;
    auto res = s.spiralOrder(m);

    for (auto &i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

