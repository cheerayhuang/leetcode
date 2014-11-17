/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: remove-duplicates-from-sorted-array.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-17-2014 16:31:57
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <climits>
#include <iterator>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (A == nullptr) {
            return 0;
        }

        auto a = A;
        auto ori = a[0];
        for (auto i = 1; i < n; ++i) {
            if (a[i] == ori) {
                a[i] = INT_MIN;
            }
            else {
                ori = a[i];
            }
        }

        auto dest = 0;
        auto src = 0;
        while (dest < n && src < n) {
            while(dest < n && a[dest] != INT_MIN) ++dest;
            if (dest == n) {
                break;
            }
            src = dest + 1;
            while(src < n && a[src] == INT_MIN) ++src;

            a[dest] = a[src];
            a[src] = INT_MIN;
        }

        return dest;
    }
};

int main() {
    //int a[] = {1, 1, 2, 2, 3, 3, 4, 4};
    //int a[] = {1, 2, 4, 4, 5};
    //int a[] = {1, 2, 3, 4, 5};
    //int a[] = {1, 2};
    //int a[] = {1, 1, 1, 1, 2, 3, 4, 5};
    //int a[] = {1, 2, 3, 4, 5, 5, 5, 5};
    //int a[] = {1, 1, 2};
    int a[] = {1, 1, 1};
    //int a[0];


    Solution s; 
    ostream_iterator<int> os_iter(cout, " ");

    auto l = s.removeDuplicates(a, 3);
    cout << l << endl;
    copy(a, a+l, os_iter);
    cout << endl; 
    //cout << s.removeDuplicates(a, 3) << endl;

    return 0;
}

