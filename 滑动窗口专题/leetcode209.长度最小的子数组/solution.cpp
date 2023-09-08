/*
问题描述：
https://leetcode.cn/problems/minimum-size-subarray-sum

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int res = INT32_MAX;                    // 初始长度定义为整型最大值！
        int left = 0;                           // 左指针（左窗口边界）
        int sum = 0;                            // 记录和
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            while(sum >= target){
                // 计算当前长度【闭区间】
                int len = i - left + 1;
                // 更新最短长度
                res = res > len ? len:res;
                // 左窗口滑动
                sum -= nums[left++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};