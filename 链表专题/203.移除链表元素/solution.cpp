// /*
// 问题描述：https://leetcode.cn/problems/remove-linked-list-elements/
// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 
// 示例 1：

// 输入：head = [1,2,6,3,4,5,6], val = 6
// 输出：[1,2,3,4,5]

// 示例 2：

// 输入：head = [], val = 1
// 输出：[]

// 示例 3：

// 输入：head = [7,7,7,7], val = 7
// 输出：[]
 

// 提示：

// 列表中的节点数目在范围 [0, 10e4] 内
// 1 <= Node.val <= 50
// 0 <= val <= 50
// */

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// /* 不含哨兵结点：递归法 */
// class Solution {
// public:
//     // 递归相当于深度探索到链表尾部！从尾部开始判断并返回
//     ListNode* removeElements(ListNode* head, int val) {
//         // 1. 只要结点为空就返回
//         if(!head) return head;
//         head->next = removeElements(head->next, val);   
//         return head->val == val ? head->next : head;    // 判断是否为目标值
//     }
// };

// // /* 不含哨兵结点：非递归法 */
// // class Solution {
// // public:
// //     // 不设定哨兵结点法
// //     ListNode* removeElements(ListNode* head, int val) {
// //         // 1. 判空表
// //         if(!head) return head;
// //         // 2. 判断表头是否为目标：若是目标头结点移动
// //         while(head && head->val == val){
// //             // 写法二：释放空间
// //             ListNode* temp = head;
// //             head = temp->next;
// //             delete temp;
// //             // 写法一：忽略空间消耗
// //             // head = head->next;
// //         }
// //         // 3. 到此为止，头结点就不是目标值了！
// //         ListNode* ptr = head;   // 设置游标结点（此时，head相当于哨兵结点）
// //         if(!ptr) return head;   // 由于 head 可能是空！所以必须判断！
// //         while(ptr->next){
// //             if(ptr->next->val == val){
// //                 ptr->next = ptr->next->next;
// //             }else{
// //                 ptr = ptr->next;
// //             }
// //         }
// //         return head;

// //     }
// // };

// // /* 含哨兵结点 */
// // class Solution {
// // public:
// //     // 设定哨兵结点法：便于删除
// //     ListNode* removeElements(ListNode* head, int val) {
// //         ListNode* ptr = new ListNode(0, head);

// //         if(!ptr->next) return ptr->next;    // 空表情形
// //         // 非空表处理如下：
// //         // 设置游标结点：辅助删除
// //         ListNode* temp = ptr;
// //         while(temp->next){
// //             if(temp->next->val == val){
// //                 temp->next = temp->next->next;
// //             }else{
// //                 temp = temp->next;
// //             }
// //         }
// //         return ptr->next;
// //     }
// // };