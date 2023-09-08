/*
问题描述：
https://leetcode.cn/problems/max-consecutive-ones-iii

给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

示例 1：
输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。

示例 2：
输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 
提示：
1 <= nums.length <= 105
nums[i] 不是 0 就是 1
0 <= k <= nums.length

*/


/*
思路：
    0 的翻转可能不容易，但是转换思路：原问题 => 问：指定区间内最多个数！
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 滑动窗口：变长区间内统计 0 的个数
        int zero = 0;                           // 记录窗口内的 0 的个数
        int res = 0;                            // 记录最长长度
        for(int left = 0, right = 0;right < nums.size();right++){
            // 无论是任何值都要进入窗口，但是遇到 0 需要计数
            if(nums[right] == 0) zero++;
            // 对 0 的个数进行检查
            while(zero > k){
                if(nums[left++] == 0) zero--;   // 让 0 的个数合法化
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};