/*
问题描述：
https://leetcode.cn/problems/reorder-list/

给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]

示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]

提示：
链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
/*
    思路：
        原表分两半，后半逆序，双选入新
        1 2 3 4 => 1 4 2 3
        等价于
            1 2
            4 3
        两个链表按照一定顺序合并！
    1. 找到中间结点：快慢指针法
    2. 后半逆序：头插法 / 双指针
    3. 合并链表：双指针
*/
    void reorderList(ListNode* head) {
        // 边界处理
        if(!head || !head->next || !head->next->next) return;

        // 1. 找到中间结点：快慢指针法
        ListNode* slow = head, * fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        // 注意：slow 的落点！
        // 奇数：刚好在中间！
        // 偶数：在后半部分的开头！
        
        // 2. 后半逆序：头插法 / 双指针      
        ListNode* head2 = new ListNode(0);
        ListNode* cur = slow->next;
        slow->next = nullptr;           // 分离链表：成为两个待合并链表！
        while(cur){
            // 头插法实现逆序
            ListNode* next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = next;
        }
        
        // 3. 合并链表：双指针
        ListNode* ret = new ListNode(0);
        ListNode* prev = ret;
        ListNode* cur1 = head, * cur2 = head2->next;
        while(cur1){
            prev->next = cur1;
            cur1 = cur1->next;
            prev = prev->next;

            if(cur2){
                prev->next = cur2;
                cur2 = cur2->next;
                prev = prev->next;
            }
        }

        delete head2;
        delete ret;
    }
};