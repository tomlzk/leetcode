/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

// #include<iostream>
// using namespace std;
// #include<vector>

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    bool judge(TreeNode *rootleft, TreeNode *rootright)
    {
        if((rootleft == NULL) ^ (rootright == NULL))
        {
            return false;
        }

        if(rootleft == NULL)
        {
            return true;
        }
        // 异或是不相同为1
        if ((rootleft->left == NULL) ^ (rootright->right == NULL))
        {
            return false;
        }

        if((rootleft->right == NULL) ^ (rootright->left == NULL))
        {
            return false;
        }

        if (rootleft->left != NULL)
        {
            if (rootleft->left->val != rootright->right->val)
            {
                return false;
            }
        }
        
        if(rootleft->right != NULL)
        {
            if(rootleft->right->val != rootright->left->val)
            {
                return false;
            }
        }
        
        if(rootleft->left == NULL && rootright->left == NULL)
        {
            return true;
        }
        

        return judge(rootleft->left, rootright->right) && judge(rootleft->right, rootright->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->left == NULL ^ root->right == NULL)
        {
            return false;
        }

        if (root->left != NULL)
        {
            if (root->left->val != root->right->val)
            {
                return false;
            }
            else
            {
                return judge(root->left, root->right);
            }
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end
