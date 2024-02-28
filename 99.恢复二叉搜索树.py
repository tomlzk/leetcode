#
# @lc app=leetcode.cn id=99 lang=python3
#
# [99] 恢复二叉搜索树
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

class Solution:

    def __init__(self) -> None:
        self.result = []
        self.count = 0

    def inorderTrack(self, root:Optional[TreeNode]) ->None:
        if root is None :
            return
        
        self.inorderTrack(root.left)
        self.result.append(root.val)
        self.inorderTrack(root.right)

    def changeTrack(self, root: Optional[TreeNode], x:int, y:int) -> None :
        if root is None :
            return
        
        self.changeTrack(root.left, x, y)
        if self.count == x :
            root.val = self.result[x]

        if self.count == y :
            root.val = self.result[y]

        self.count += 1
        self.changeTrack(root.right, x, y)

    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        self.inorderTrack(root)
        temp = self.result[:]
        self.result.sort()
        now = []

        for i in range(len(temp)):
            if temp[i] is not self.result[i] :
                now.append(i)
            
        self.changeTrack(root, now[0], now[1])
# @lc code=end

