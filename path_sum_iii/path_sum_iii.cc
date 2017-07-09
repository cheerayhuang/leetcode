/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: path_sum_iii.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-09-2017 17:11:57
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    vector<int> CountSum(TreeNode* root) {
        vector<int> left_sums, right_sums;

        if (root->left != nullptr)
            left_sums = CountSum(root->left);

        if (root->right != nullptr) {
            right_sums = CountSum(root->right);
        }

        vector<int> sums(left_sums.begin(), left_sums.end());
        sums.insert(sums.end(), right_sums.begin(), right_sums.end());

        vector<int> new_sums;
        transform(sums.begin(), sums.end(), back_inserter(new_sums), [&root](int i){return i + root->val;});
        new_sums.push_back(root->val);

        count_ += count(new_sums.begin(), new_sums.end(), sum_);

        return new_sums;
    }

    int sum_;
    int count_;

public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;

        sum_ = sum;
        count_ = 0;

        CountSum(root);

        return count_;
    }
};

int main() {
    TreeNode *t = new TreeNode(5);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    t->left->right = new TreeNode(5);
    t->right->left = new TreeNode(-2);
    t->right->right = new TreeNode(3);

    Solution s;
    cout << s.pathSum(t, 4) << endl;
    cout << s.pathSum(t, 5) << endl;
    cout << s.pathSum(t, 1) << endl;
    cout << s.pathSum(t, 3) << endl;
    cout << s.pathSum(nullptr, 3) << endl;

    return 0;
}


