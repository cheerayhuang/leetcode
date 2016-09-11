/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: rotate_function.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-11-2016 09:40:42
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        auto size = A.size();
        if (size == 0) return 0;

        long long vec_sum = 0;
        for_each(A.begin(), A.end(), [&](int i) { vec_sum += i;});
        if (vec_sum == 0) return 0;


        long long max = 0;
        for (auto i = 0; i < size; ++i) {
            max += i * A[i];
        }

        long long last_f = max;
        for (auto i = 1; i < size; ++i) {
            long long cur_f = 0;
            auto tail = *(A.end()-1);
            cur_f = last_f - tail * (size-1) + vec_sum - tail;

            if (cur_f > max) max = cur_f;
            last_f = cur_f;

            auto tmp = *(A.end()-1);
            A.insert(A.begin(), tmp);
            A.erase(A.end()-1);
        }

        return static_cast<int>(max);
    }
};


int main() {
    Solution s;

    vector<int> vec {4, 3, 2, 6};

    cout << s.maxRotateFunction(vec) << endl;

    return 0;
}
