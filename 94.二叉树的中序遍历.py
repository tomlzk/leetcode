#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Optional
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# result = []
# def mediumTraversal(root: Optional[TreeNode]):
#     if root is None :
#         return
    
#     mediumTraversal(root.left)
#     result.append(root.val)
#     mediumTraversal(root.right)

class Solution:
    def __init__(self) -> None:
        result = []

    def mediumTraversal(self, root: Optional[TreeNode]):
        if root is None :
            return
        
        self.mediumTraversal(root.left)
        self.result.append(root.val)
        self.mediumTraversal(root.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.mediumTraversal(root)
        return self.result
# @lc code=end