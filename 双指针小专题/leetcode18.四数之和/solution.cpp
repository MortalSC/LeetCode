/*
问题描述
https://leetcode.cn/problems/4sum/description/

给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
（若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        // 1. 有序化处理
        sort(nums.begin(), nums.end());
        // 2. 套娃：固定一个数 => 三数之和【再固定一个数 => 两数之和】
        int size = nums.size();
        for(int i = 0; i < size; ){
            for(int j = i+1 ; j < size;){
                int left =j+1,right =size-1;
                long long aim = (long long)target - nums[i] - nums[j];
                // int aim = target - nums[i] - nums[j];

                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum > aim) right--;
                    else if(sum < aim) left++;
                    else{
                        ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++,right--;
                        // 去重！！！
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                }
                // 去重！
                j++;
                while(j < size && nums[j] == nums[j-1]) j++;
            }
            // 去重！
            i++;
            while(i <size && nums[i] == nums[i-1]) i++;
        }
        return ret;
    }
};