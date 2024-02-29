/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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

// #include<iostream>
// #include<vector>
// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head == NULL)
        {
            return NULL;
        }
        int len = 1;
        ListNode *q = head;
        for(; q->next != NULL; q = q->next, len++);
        q->next = head;

        int m = k % len;
        m = len - m;

        ListNode *temp = q->next;
        for(int i = 0; i < m; i++)
        {
            q = q->next;
            temp = temp->next;
        }

        q->next = NULL;
        return temp;

    }
};
// @lc code=end
