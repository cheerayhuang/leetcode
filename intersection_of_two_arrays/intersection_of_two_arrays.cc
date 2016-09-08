/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: intersection_of_two_arrays.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 15:21:06
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;

        for_each(nums1.begin(), nums1.end(), [&](int i) { s.insert(i); });

        unordered_set<int> r;

        for (auto i : nums2) {
            if (s.count(i)) {
                r.insert(i);
            }
        }

        return std::move(vector<int> (r.begin(), r.end()));
    }
};

int main() {

    vector<int> vec1 {1, 2, 2};
    vector<int> vec2 {2, 2, 3};
    vector<int> vec3;

    vec3.resize(2);

    ostream_iterator<int> iter_cout(cout, " ");

    set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
    copy(vec3.begin(), vec3.end(), iter_cout);

    cout << endl;

    Solution s;

    auto vec4 = s.intersection(vec1, vec2);

    copy(vec4.begin(), vec4.end(), iter_cout);
    cout << endl;

    vec1 = {5};
    vec2 = {5, 5};
    vec4 = s.intersection(vec1, vec2);
    copy(vec4.begin(), vec4.end(), iter_cout);
    cout << vec4.size() << endl;

    vec1.clear();
    //vec2.clear();
    vec4 = s.intersection(vec1, vec2);
    copy(vec4.begin(), vec4.end(), iter_cout);
    cout << vec4.size() << endl;

    return 0;
}


