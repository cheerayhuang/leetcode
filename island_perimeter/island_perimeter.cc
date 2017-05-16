/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: island_perimeter.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-16-2017 22:27:25
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto start_x = 0;
        auto start_y = 0;

        for(auto i = 0; i < grid.size(); ++i) {
            auto column_iter = find(grid[i].begin(), grid[i].end(), 1);
            if (column_iter != grid[i].end()) {
                start_x = i;
                start_y = column_iter - grid[i].begin();
                break;
            }
        }

        vector<pair<int, int>> direct{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        deque<pair<int, int>> islands{{start_x, start_y}};
        auto width = grid[0].size();
        auto length = grid.size();
        auto num_islands = 0;
        auto shared_edges = 0;

        while (!islands.empty()) {
            num_islands++;
            auto cur = islands.front();
            islands.pop_front();
            for (auto d : direct) {
                auto new_x = cur.first + d.first;
                auto new_y = cur.second + d.second;
                if (new_x < 0 || new_x >= length || new_y < 0 || new_y >= width) continue;
                if (find_if(islands.begin(), islands.end(), [=](pair<int, int> p) { return p == make_pair(new_x, new_y);}) != deque.end()) {
                    shared_edges++;
                    continue;
                }

                if (grid.at(new_x).at(new_y)) {
                    islands.push_back(make_pair<int, int>(std::move(new_x), std::move(new_y)));
                    shared_edges++;
                }
            }

            grid.at(cur.first).at(cur.second) = 0;
        }

        return 4*num_islands - 2*shared_edges;

    }
};

int main() {
    return 0;
}


