/*
问题描述：

给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

示例 2：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
 

提示：
链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* 模拟 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* cur = head;
        while(cur){
            ++size;
            cur = cur->next;
        }
        int loop = size / k;            // 需要处理的片段个数

        ListNode* newhead = new ListNode(0, nullptr);    // 引入哨兵结点
        ListNode* prev = newhead;
        cur = head;

        for(int i = 0;i<loop;i++){
            ListNode* temp = cur;
            for(int j = 0;j < k;j++){
                ListNode* next = cur->next; // 记录当前结点的下一个位置
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = temp;
        }

        prev->next = cur;
        cur = newhead->next;
        delete newhead;
        return cur;
    }
};