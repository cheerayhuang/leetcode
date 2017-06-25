/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: k_inverse_pairs_arrary.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 06-25-2017 16:00:32
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ModuloResult(int i) {
        return i % (static_cast<int>(10e8) + 7);
    }

    int kInversePairs(int n, int k) {
        if (k == 0) return 1;
        auto end_k = k;

        vector<int> f(1001);
        vector<int> cur(1001);
        f[0] = 1;

        for (auto i = 2; i <= n; ++i) {
            for(auto k = 0; k <= 1000; ++k) {
                if (k > end_k) break;
                if (k > 0) {
                    cur[k] = ModuloResult(cur[k-1]);
                }
                cur[k] += ModuloResult(f[k]);
                cur[k] = ModuloResult(cur[k]);
                if (k-(i-1)-1 >= 0) {
                    cur[k] -= ModuloResult(f[k-(i-1)-1]);
                    if (cur[k] < 0) cur[k] += static_cast<int>(10e8) + 7;
                }
                //cur[k] = ModuloResult(cur[k]);
            }
            f = cur;
            cur.assign(1001, 0);
        }

        return f[k];
    }
};

int main() {
    Solution s;

    /*cout << s.kInversePairs(3, 1) << endl;
    cout << s.kInversePairs(3, 2) << endl;
    cout << s.kInversePairs(2, 1) << endl;
    cout << s.kInversePairs(2, 0) << endl;
    cout << s.kInversePairs(1000, 1) << endl;
    */
    //cout << s.kInversePairs(50, 8) << endl;
    cout << s.kInversePairs(247, 965) << endl;
    cout << s.kInversePairs(1000, 965) << endl;
    cout << s.kInversePairs(1000, 999) << endl;

    return 0;
}
