/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: covert_sorted_array_to_binary_search_tree.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-30-2017 15:16:27
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto l = nums.size();
        if (l == 0) return nullptr;

        TreeNode* t = new TreeNode(nums[l/2]);

        auto left = vector<int>(nums.begin(), nums.begin()+l/2);
        auto right = vector<int>(nums.begin()+l/2+1, nums.end());

        t->left = sortedArrayToBST(left);
        t->right = sortedArrayToBST(right);

        return t;
    }
};

int main() {

    vector<int> v1 {1};

    vector<int> v2(v1.begin(), v1.begin());
    vector<int> v3(v1.end(), v1.end());

    cout << v2.size() << endl;
    cout << v3.size() << endl;

    return 0;
}

