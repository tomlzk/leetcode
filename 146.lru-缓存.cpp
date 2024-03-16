/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <unordered_map>

struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr)
    {
    }
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr)
    {
    }
};

class LRUCache
{
public:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;

    // 初始化的作用
    // capacity表示容量
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->next = head;
    }

    int get(int key)
    {
        // 如果key不存在，返回-1
        if (!cache.count(key))
        {
            return -1;
        }
        // 如果key存在，先通过哈希表定位，再移到头部
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            // key不存在，就创建一个新节点
            DLinkedNode *node = new DLinkedNode(key, value);
            // 将该节点存入哈希表cache
            cache[key] = node;
            // 将该节点存入双向链表的头部
            addToHead(node);
            // 表示双向链表的大小变大
            size++;

            if (size > capacity)
            {
                // 如果超出容量，就要删除双向链表的尾部节点
                DLinkedNode *removed = removeTail();
                // 然后删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存内泄
                delete removed;
                size--;
            }
        }
        else
        {
            // 如果key存在， 先通过哈希表定位，再修改value,并移动到头部
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
