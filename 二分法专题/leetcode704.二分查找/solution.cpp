/*
问题描述：
https://leetcode.cn/problems/binary-search/
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
*/

#include <bits/stdc++.h>
using namespace std;

// 方法一：通过二段法写二分条件
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if(nums[left] == target) return left;
        return -1;
    }
};

// 方法二：左闭右开区间法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (( right - left ) / 2) ;     // 写法：防止溢出
            if(target < nums[mid]){
                // 说明目标可能在左！
                // mid 不是目标即为新区间的尾部的下一个位置！
                right = mid;                
            }else if(target > nums[mid]){
                // 说明目标可能在右！
                // mid 不是目标即为原区间 mid 的下一个位置是新区间的开始！！
                left = mid + 1;             
            }else return mid;
        }
        return -1;
    }
};

// 方法三：左闭右闭区间法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (( right - left ) / 2) ;     // 写法：防止溢出
            if(target < nums[mid]){
                // 说明目标可能在左！
                // mid 不是目标即为新区间的尾部是 mid 的前一个位置！
                right = mid - 1;                
            }else if(target > nums[mid]){
                // 说明目标可能在右！
                // mid 不是目标，即为 mid 的下一个位置是新区间的开始！！
                left = mid + 1;             
            }else return mid;
        }
        return -1;
    }
};
