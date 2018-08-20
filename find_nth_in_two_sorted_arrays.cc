/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: 1.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 10-14-2017 11:41:35
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;


int func(int k, vector<int>& a, vector<int>& b) {
    auto len_a = a.size();
    auto len_b = b.size();

    if (k > len_a + len_b) {
        cout << "Does not exist." << endl;
        return INT_MIN;
    }

    if (k == 1) {
        return a[0] <= b[0] ? a[0] : b[0];
    }

    auto m = k / 2;
    auto n = k - m;

    // index from 0.
    --m;
    --n;
    --len_a;
    --len_b;

    if (m > len_a) {
        n += m - len_a;
        m = len_a;
    }

    if (n > len_b) {
        m += n - len_b;
        n = len_b;
    }

    while (true) {
        if (n == -1) {
            return a[m];
        }

        if (m == -1) {
            return b[n];
        }

        if (a[m] >= b[n] && (n == len_b || a[m] <= b[n+1])) {
            return a[m];
        }

        if (b[n] >= a[m] && (m == len_a || b[n] <= a[m+1])) {
            return b[n];
        }

        auto next_n = 0;
        auto next_m = 0;
        if (a[m] < b[n]) {
            next_m = (len_a+m+1) / 2;
            if (n == 0) {
                next_n = -1;
            }
            else {
                next_n = n / 2;
            }

            if (n - next_n > next_m - m) {
                n -= next_m -m;
                m = next_m;
            }
            else {
                m += n - next_n;
                n = next_n;
            }
        }
        else {
            next_n = (len_b+n+1) / 2;
            if (m == 0) {
                next_m = -1;
            }
            else {
                next_m = m / 2;
            }

            if (next_n - n > m - next_m) {
                n += m - next_m;
                m = next_m;
            }
            else {
                m -= next_n - n;
                n = next_n;
            }
        }
    }
}

int main() {
    vector<int> a {1, 2};
    vector<int> b {1, 2, 3, 4, 5, 6, 7};
    cout << func(6, a, b) << endl;
    cout << func(8, a, b) << endl;

    a.assign({1, 2, 3});
    b.assign({4, 5, 6, 7});
    cout << func(6, a, b) << endl;
    cout << func(4, a, b) << endl;
    cout << func(2, a, b) << endl;
    cout << func(3, a, b) << endl;

    a.assign(10, 1);
    b.assign(8, 5);
    cout << func(6, a, b) << endl;
    cout << func(5, a, b) << endl;
    cout << func(11, a, b) << endl;
    cout << func(18, a, b) << endl;
    cout << func(19, a, b) << endl;

    a.assign({1, 3, 5, 7, 9, 11});
    b.assign({2, 4, 6, 8, 10, 12, 14, 16, 18, 20});
    cout << func(1, a, b) << endl;
    cout << func(3, a, b) << endl;
    cout << func(13, a, b) << endl;
    cout << func(5, a, b) << endl;
    cout << func(10, a, b) << endl;
    cout << func(16, a, b) << endl;

    return 0;
}
