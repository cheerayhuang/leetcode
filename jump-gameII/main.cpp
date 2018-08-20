/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: main.cpp
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-20-2018 12:44:54
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    int jump(vector<int>&& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return 1;

        vector<int> s(nums.size());

        for (auto iter = s.begin()+1; iter != s.end(); iter++) {
            *iter = *(iter-1)+1;
        }

        for (auto i = 2; i < s.size(); i++) {
            for (auto j = 0; j < i; j++) {
                if (nums[j] + j >= i && s[j] + 1 < s[i]) {
                    s[i] = s[j]+1;
                }
            }
        }

        ostream_iterator<int> o_iter(cout);

        copy(nums.begin(), nums.end(), o_iter);
        cout << endl;
        copy(s.begin(), s.end(), o_iter);

        return s[s.size()-1];
    }
};

int main() {
    Solution s;
    cout << s.jump(vector<int>{2, 3, 1, 1, 4}) << endl;

    return 0;
}
