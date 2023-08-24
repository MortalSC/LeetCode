/*
问题描述：
https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：
输入：head = [1,3,2]
输出：[2,3,1]


限制：0 <= 链表长度 <= 10000
*/

// 思路一：遍历链表，数据存储入栈（stack：出栈输出数据；vector模拟栈：逆序打印）
// 思路二：递归法 + vector模拟栈

#include <vector>
#include <algorithm>
using namespace std;

// 牛客：返回一向量的形式
// 递归思路
class Solution {
  public:
    void GetRet(vector<int>& ret, ListNode* head) {
        if (!head) return;
        GetRet(ret, head->next);
        ret.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        GetRet(ret, head);
        return ret;
    }
};

// 力扣：返回一向量的形式
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ret;
        ListNode *cur = head;
        while (cur)
        {
            ret.push_back(cur->val);
            cur = cur->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};



