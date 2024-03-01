/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void preorder(vector<int> &res, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        res.push_back(root->val);
        preorder(res, root->left);
        preorder(res, root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        preorder(res, root);
        return res;
    }
};
// @lc code=end
