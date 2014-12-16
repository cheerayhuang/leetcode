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
        if (A == nullptr || n == 0) {
            return 0;
        }

        auto a = A;
        auto ori = a[0];
        auto dest = 1;
        auto duplicate_count = 1;
        for (auto i = 1; i < n; ++i) {
            if (duplicate_count == 2 && a[i] == ori) {
                continue;
            }
            else {
                a[dest++] = a[i];
                if (a[i] == ori) {
                    ++duplicate_count;
                }
                else {
                    duplicate_count = 1;
                    ori = a[i];
                }
            }
        }

        return dest;
    }
};

int main() {
    int a[] = {1, 1, 2, 2, 3, 3,3,  4, 4, 4, 4, 4};
    //int a[] = {1, 2, 4, 4, 5};
    //int a[] = {1, 2, 3, 4, 5};
    //int a[] = {1, 2};
    //int a[] = {1, 1, 1, 1, 2, 3, 4, 5};
    //int a[] = {1, 2, 3, 4, 5, 5, 5, 5};
    //int a[] = {1, 1, 2};

    Solution s; 
    ostream_iterator<int> os_iter(cout, " ");

    auto l = s.removeDuplicates(a, 12);
    cout << l << endl;

    copy(a, a+l, os_iter);
    cout << endl; 

    return 0;
}

