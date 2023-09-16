/*
问题描述：


给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 方法二：分治 - 递归 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, lists.size()-1);
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right){
        if(left > right) return nullptr;
        if(left == right) return lists[left];

        int mid = (left + right) >> 1;
        ListNode* l1 = mergeSort(lists, left, mid);
        ListNode* l2 = mergeSort(lists, mid+1, right);

        return mergeToLists(l1,l2);
    }

    ListNode* mergeToLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head = new ListNode(0,nullptr);
        ListNode* cur1 = l1, * cur2 = l2, *prev = head;
        
        while(cur1 && cur2){
            if(cur1->val <= cur2->val){
                prev = prev->next = cur1;
                cur1 = cur1->next;
            }else
            {
                prev = prev->next = cur2;
                cur2 = cur2->next;
            }
        }
        if(cur1) prev->next = cur1;
        if(cur2) prev->next = cur2;
        return head->next;

    }
};


 /* 方法一：使用堆（借助优先级队列） */
class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 创建一个小根堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

        // 所有头结点存入小根堆
        for(auto l : lists)
            if(l) heap.push(l);
        
        // 合并k个有序链表
        ListNode* ret = new ListNode(0);
        ListNode* prev = ret;
        while(!heap.empty()){
            ListNode* t = heap.top();       // 获取堆顶
            heap.pop();
            prev->next = t;
            prev = t;
            if(t->next) heap.push(t->next);
        }
        prev = ret->next;
        delete ret;
        return prev;
    }
};