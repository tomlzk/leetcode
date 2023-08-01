/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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



class Solution
{
public:
    map<int, int> index;
    TreeNode *MybuiltTree(vector<int> &preorder, vector<int> &inorder, int preorder_before, int preorder_later, int inorder_before, int inorder_later)
    {
        if (preorder_before > preorder_later)
        {
            return nullptr;
        }
        //根节点的数值
        int preorder_root = preorder[preorder_before];
        //根节点的下标
        int temp = index[preorder_root];
        TreeNode *root = new TreeNode(preorder_root);
        //左子树的数量
        int leftsize = temp - inorder_before;
        //右子树的数量
        int rightsize = inorder_later - temp;

        root->left = MybuiltTree(preorder, inorder, preorder_before + 1, preorder_before + leftsize, inorder_before, inorder_before + leftsize - 1);

        root->right = MybuiltTree(preorder, inorder, preorder_before + leftsize + 1, preorder_before + leftsize + rightsize, temp + 1, temp + rightsize);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        return MybuiltTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end
