/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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


// #include <iostream>
// using namespace std;
// #include <vector>
// #include <algorithm>
// #include <map>

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

    vector<int> result;
    int count = 0;

    void inorderTrack(TreeNode *root)
    {
        if(root == NULL)
        {
            return ;
        }

        inorderTrack(root->left);
        result.push_back(root->val);
        inorderTrack(root->right);
    }

    void changeTrack(TreeNode * & root, int x, int y)//可能出错
    {
        if(root == NULL)
        {
            return ;
        }

        changeTrack(root->left, x, y);
        if(count == x)
        {
            root->val = result[x];
        }

        if(count == y)
        {
            root->val = result[y];
        }
        count++;
        changeTrack(root->right, x, y);
    }

    void recoverTree(TreeNode *root)
    {
        inorderTrack(root);
        vector<int> temp = result;
        sort(result.begin(), result.end());

        //map<int, int> now;
        vector<int> now;

        for(int i = 0; i < temp.size(); i++)
        {
            if(temp[i] != result[i])
            {
                //now.insert(pair<int, int>(i, 1));
                now.push_back(i);
            }
        }

        changeTrack(root, now[0], now[1]);
    }
};
// @lc code=end
