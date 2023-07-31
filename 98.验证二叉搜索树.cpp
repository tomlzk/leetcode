/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//#include<limits.h>
class Solution
{
public:
    bool backstrack(TreeNode *root, long under, long upper)
    {
        if(root == nullptr)
        {
            return true;
        }
        if(root->val <= under || root->val >= upper)
        {
            return false;
        }
        return backstrack(root->left, under, root->val) && backstrack(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root)
    {
        return backstrack(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
