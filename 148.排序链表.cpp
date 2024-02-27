/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
// 头指针不为空，其中的val有实际存在的数据
// 此方法为归并排序，思想是分治法
// 归并就是将两个有序表合并为一个有序表
// 因为需要两个有序表，所以需要不断的分下去
// 刚开始的时候有一个疑惑，疑惑的原因是忽略了需要两个有序表这个条件，而不是单纯的两个表即可。

//细节问题
//1.关于分治，下列方法算前不算后
//2.我更希望使用前后都算的方式，此方法将以python的方式显示出来
//3.在merge函数中可以看出，在内存中head1与head2已经改变了
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
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        if(head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        ListNode * fast = head;
        ListNode * slow = head;

        while(fast != tail)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast != tail)
            {
                fast = fast->next;
            }
        }

        return merge(sortList(head, slow), sortList(slow, tail));
    }

    ListNode * merge(ListNode * head1, ListNode * head2)
    {
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        
        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        if(temp1 != nullptr)
        {
            temp->next = temp1;
        }
        else if(temp2 != nullptr)
        {
            temp->next = temp2;
        }

        return head->next;
    }
};
// @lc code=end
