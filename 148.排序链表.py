#
# @lc app=leetcode.cn id=148 lang=python3
#
# [148] 排序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional


class Solution:
    # def List(self, head: Optional[ListNode], tail: Optional[ListNode]) -> Optional[ListNode]:
    #     if head == None :
    #         return None
        
    #     if head.next == tail :
    #         head.next = None
    #         return head
        
    #     fast = head
    #     slow = head

    #     while fast != tail :
    #         fast = fast.next
    #         slow = slow.next
    #         if fast != tail :
    #             fast = fast.next

    #     return self.merge(self.List(head, slow), self.List(slow, tail))
        

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #self.List(head, None)
        def List(head: Optional[ListNode], tail: Optional[ListNode]) -> Optional[ListNode]:
            if head == None :
                return None
            
            if head.next == tail :
                head.next = None
                return head
            
            fast = head
            slow = head

            while fast != tail :
                fast = fast.next
                slow = slow.next
                if fast != tail :
                    fast = fast.next

            return merge(List(head, slow), List(slow, tail))
    
        def merge(head1 : Optional[ListNode], head2 : Optional[ListNode]) -> Optional[ListNode] :
            head = ListNode()
            temp = head
            temp1 = head1
            temp2 = head2

            while temp1 != None and temp2 != None :

                if temp1.val <= temp2.val :
                    temp.next = temp1
                    temp1 = temp1.next
                else :
                    temp.next = temp2
                    temp2 = temp2.next
                temp = temp.next


            if temp1 != None :
                temp.next = temp1
            if temp2 != None :
                temp.next = temp2

            return head.next
        return List(head, None)

    
    # def merge(self, head1 : Optional[ListNode], head2 : Optional[ListNode]) -> Optional[ListNode] :
    #     head = ListNode()
    #     temp = head
    #     temp1 = head1
    #     temp2 = head2

    #     while temp1 != None and temp2 != None :

    #         if temp1.val <= temp2.val :
    #             temp.next = temp1
    #         else :
    #             temp.next = temp2
            
    #         temp = temp.next


    #     if temp1 != None :
    #         temp.next = temp1
    #     if temp2 != None :
    #         temp.next = temp2

    #     return head.next


        

# @lc code=end

