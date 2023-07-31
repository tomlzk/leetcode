/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    int getlength(ListNode *head)
    {
        int i = 1;
        for (; head->next != NULL; i++)
        {
            head = head->next;
        }
        return i;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = new ListNode();
        temp->next = head;
        int length = getlength(head);
        ListNode * now = temp;
        // if(length == n)
        // {
        //     return NULL;
        // }
        for(int i = 0; i < length - n; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp = now->next;
        return temp;
    }
};
// @lc code=end
