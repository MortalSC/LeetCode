/*
问题描述：
https://leetcode.cn/problems/swap-nodes-in-pairs/description/

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
 

提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* 迭代法 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        // 设置哨兵头结点
        ListNode* phead = new ListNode(0, head);
        ListNode* cur = phead;
        ListNode* prev = cur->next;
        ListNode* mid = prev->next;
        ListNode* tail = mid->next;
        while(prev && mid){
            cur->next = mid;
            mid->next = prev;
            prev->next = tail;

            // c p m t => c m p t
            cur = prev;
            prev = tail;
            if(tail) mid = prev->next;
            if(mid) tail = mid->next;
        }
        cur = phead->next;
        delete phead;
        return cur;
    }
};