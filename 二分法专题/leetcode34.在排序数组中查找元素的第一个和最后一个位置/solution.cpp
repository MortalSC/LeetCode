/*
问题描述：
https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。


示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums 是一个非递减数组
-10^9 <= target <= 10^9
*/

/*
    思路：
        两次查找：重点找到二段性的分界点
        左端点：[开始，小于target] 和 其他
        右端点：[开始，目标右边界] 和 其他
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 特殊情况的处理
        if(nums.size() == 0) return {-1,-1};
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;               // 分界点处小于，目标不存在 / 一定在右边
            else right = mid;
            // 跳出循环时，一定有指向target / 不存在 target
        }
        if(nums[left] != target) return {-1,-1};
        int start = left;
        right = nums.size() -1;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if(nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        return {start, left};
    }
};


