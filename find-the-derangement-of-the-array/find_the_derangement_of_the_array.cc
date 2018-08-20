/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: find_the_derangement_of_the_array.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-02-2017 12:41:47
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <stdint.h>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {

private:
    int ModuleNum(int64_t n) {
        return n % static_cast<int>(1e9+7);
    }

    int CompleteP(int n) {

        auto sum = 1;
        for (auto i = n; i > 1; --i) {
            sum *= i;
            sum = ModuleNum(sum);
        }

        return sum;
    }

public:
    int findDerangement(int n) {
        vector<int> res(n+1, 0);
        res[2] = 1;

        for (auto i = 3; i <=n; ++i) {
            int64_t last_c = 1;
            auto k = i;
            auto sum = CompleteP(i);
            for(auto j = 1; j <= i - 2; ++j, --k) {
                int64_t tmp = last_c * k / j;
                last_c = tmp;
                if (tmp < 0) cout << tmp << endl;
                int64_t cur_item = static_cast<int64_t>(ModuleNum(tmp)) * static_cast<int64_t>(res[k-1]);
                if (cur_item <0) cout << cur_item << endl;
                cur_item = ModuleNum(cur_item);
                sum -= cur_item;
                if (sum < 0) sum += static_cast<int>(1e9+7);
            }

            --sum;
            if (sum < 0) sum += static_cast<int>(1e9+7);
            res[i] = sum;
        }

        ostream_iterator <int> o_iter(cout, " ");
        copy(res.begin(), res.end(), o_iter);


        return res[n];
    }
};

int main() {
    Solution s;

    cout << s.findDerangement(14) << endl;

    return 0;
}

