/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int cnt = 0;

    void dfs(TreeNode* root, int sum) {
        if (!root) return;
        sum -= root->val;
        if (sum == 0) ++cnt;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return cnt;
    }
};
// @lc code=end
