#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target)  return 0;

        vector<int> v(stations.size(), -1);

        for (auto i = 0; i < stations.size(); ++i) {
            if (startFuel >= stations[i][0]) {
                v[i] = startFuel + stations[i][1];
                if (v[i] >= target) return 1;
            }
        }

        auto curr_st = 0;
        auto cur_max = startFuel;

        auto s = v;

        for (auto n = 1; n < stations.size(); ++n)  {
            cur_max = v[n-1];
            for (auto i = n; i < stations.size(); ++i)  {
                if (i == n && cur_max < stations[i][0]) return -1;

                if (cur_max < v[i-1]) cur_max = v[i-1];
                if (cur_max >= stations[i][0]) {
                    s[i] = cur_max + stations[i][1];
                }

                if (s[i] >= target) return n+1;
            }

            v = s;
            /*
            for_each(v.begin(), v.end(), [](int i) -> void {cout << i << endl;});
            cout << "---" << endl;
            */
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
