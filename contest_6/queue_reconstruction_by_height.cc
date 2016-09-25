/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: queue_reconstruction_by_height.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-25-2016 11:04:05
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        map<int, vector<pair<int,int>>> h;

        for (auto p : people) {
            if (h.count(p.second)) {
                auto iter = h[p.second].begin();
                for (; iter != h[p.second].end();
                    ++iter) {
                    if (iter->first > p.first) break;

                }
                h[p.second].insert(iter, p);
            }
            else {
                h[p.second] = vector<pair<int,int>>{p};
            }
        }

        vector<pair<int, int>> res;

        for (auto iter = h.begin(); iter != h.end(); ++iter) {

            if (iter->first == 0) {
                res.insert(res.end(), (iter->second).begin(), (iter->second).end());
                continue;
            }

            auto val_list_iter = (iter->second).begin();
            for (; val_list_iter != (iter->second).end(); ++val_list_iter) {
                auto times = val_list_iter->second;
                auto res_iter = res.begin();
                for(; res_iter!= res.end(); ++res_iter) {
                    if(res_iter->first >= val_list_iter->first) {
                        if (times > 0) {
                            --times;
                            continue;
                        }
                        res.insert(res_iter, *val_list_iter);
                        break;
                    }
                }

                if (res_iter == res.end()) {
                    res.insert(res.end(), val_list_iter, (iter->second).end());
                    break;
                }
            }
        }

        return std::move(res);
    }
};

int main() {
    vector<pair<int, int>> v = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<pair<int, int>> v1 = {{2,4}, {3, 4}, {9, 0}, {0, 6}, {7,1}, {6,0}, {7,3}, {2,5}, {1, 1}, {8,0}};

    Solution s;
    auto res = s.reconstructQueue(v);

    for_each(res.begin(), res.end(), [](pair<int, int> p) { cout << p.first << ' ' << p.second << endl; });

    return 0;
}

