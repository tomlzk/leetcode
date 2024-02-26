// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
//按照题解所给的方法一，使用c++解题，自创方法使用java,方法二使用python
// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
#include<iostream>
using namespace std;
#include<map>
#include<vector>
class Solution {
public:

    int post_max;
    map<int, int> in;

    TreeNode* helper(int low, int high, vector<int>& inorder, vector<int>& postorder)
    {
        if(low > high)
        {
            return nullptr;
        }

        int root = postorder[post_max];
        TreeNode* treeRoot = new TreeNode(root);
        int temp = in[root];
        post_max--;

        //构造右子树
        treeRoot->right = helper(temp + 1, high, inorder, postorder);

        //构造左子树
        treeRoot->left = helper(low, temp - 1, inorder, postorder);

        return treeRoot;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        post_max = postorder.size() - 1;

        for(int i = 0; i <= post_max; i++)
        {
            in.insert(pair<int, int>(inorder[i], i));
        }
        


        return helper(0, postorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end

