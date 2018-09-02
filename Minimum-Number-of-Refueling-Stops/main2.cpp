/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: main2.cpp
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-28-2018 17:25:50
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <unordered_map>

#include "heap.hpp"

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;

        Heap bfs_q;
        bfs_q.Insert(Stop{-1, startFuel});

        auto n = 0;
        Heap q;
        unordered_map<int, bool> is_added;
        while (!bfs_q.Empty()) {
            auto s = bfs_q.Pop();

            for(auto i = s.index+1; i < stations.size(); ++i) {
                if (s.fuel >= stations[i][0]) {
                    if (is_added.find(i) != is_added.end()) {
                        //continue
                        break;
                    }

                    is_added[i] = true;
                    auto p = Stop{i, stations[i][1] + s.fuel};
                    if (p.fuel >= target) return n+1;
                    q.Insert(p);

                } else {
                    break;
                }
            }

            if (bfs_q.Empty() && !q.Empty()) {
                bfs_q = q;
                n++;
                q.Clear();
                is_added.clear();
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> s = {{13,21},{26,115},{100,47},{225,99},{299,141},{444,198},{608,190},{636,157},{647,255},{841,123}};

    Solution sol;

    cout << sol.minRefuelStops(1000, 299, s) << endl;

    s = {{14,123},{145,203},{344,26},{357,68},{390,35},{478,135},{685,108},{823,186},{934,217},{959,80}};
    cout << sol.minRefuelStops(1000, 299, s) << endl;

    return 0;
}
