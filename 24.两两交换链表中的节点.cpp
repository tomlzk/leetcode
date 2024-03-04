/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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

// #include <iostream>
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
    ListNode *swapPairs(ListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return head;
        }
        ListNode *p = head->next;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *last = second->next;

        if(last == NULL)
        {
            second->next = first;
            first->next = NULL;
        }

        while (last != NULL)
        {
            second->next = first;
            first->next = last->next;

            second = last->next;
            if (second == NULL)
            {
                first->next = last;
                break;
            }
            first = last;
            last = second->next;
            if (last == NULL)
            {
                second->next = first;
                first->next = last;
            }
        }

        return p;
    }
};
// @lc code=end
