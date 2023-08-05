/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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

    vector<TreeNode *> myGenerateTrees(int start, int end)
    {
        vector<TreeNode *> res;
        if(start > end)
        {
            return {nullptr};
        }

        for(int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftTree = myGenerateTrees(start, i - 1);

            vector<TreeNode *> rightTree = myGenerateTrees(i + 1, end);

            for(TreeNode * &left : leftTree)
            {
                for(TreeNode * &right : rightTree)
                {
                    TreeNode * temp = new TreeNode(i);
                    temp->left = left;
                    temp->right = right;
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if(n == 0)
        {
            return {};
        }
        
        return myGenerateTrees(1, n);
    }
};
// @lc code=end
