/*
问题描述：
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
*/

#include <iostream>

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

// 递归法（写法一）
// class Solution {
// public:
//     ListNode* reverse(ListNode* pre,ListNode* cur){
//         if(cur == NULL) return pre;
//         ListNode* temp = cur->next;
//         cur->next = pre;
//         // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
//         // pre = cur;
//         // cur = temp;
//         return reverse(cur,temp);
//     }
//     ListNode* reverseList(ListNode* head) {
//         // 和双指针法初始化是一样的逻辑
//         // ListNode* cur = head;
//         // ListNode* pre = NULL;
//         return reverse(NULL, head);
//     }
// };

// 递归法（写法二）
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // 边缘条件判断
//         if(head == NULL) return NULL;           // 无结点
//         if (head->next == NULL) return head;    // 剩余一个 / 只有一个返回：当前结点
        
//         // 第一次调用到此必然是：存在至少两个结点！
//         // 递归调用，翻转第二个节点开始往后的链表
//         ListNode *last = reverseList(head->next);

//         // 翻转头节点与第二个节点的指向
//         head->next->next = head;

//         // 此时的 head 节点为尾节点，next 需要指向 NULL
//         head->next = NULL;
//         return last;
//     }
// }; 


// 双指针顺序遍历处理法
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp;         // 用于记录当前反转结点的下一个结点
//         ListNode* cur = head;   // 当前反转结点
//         ListNode* prev = nullptr;   // 记录反转结点的前一个结点
//         while(cur){
//             temp = cur->next;   // 当前结点存在，则记录其下一个结点
//             cur->next = prev;   // 反转指向
//             prev = cur;         // 更新指向
//             cur = temp;         // 找到下一个将要处理的结点
//         }
//         return prev;
//     }
// };


