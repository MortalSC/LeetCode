/*
问题描述：
https://leetcode.cn/problems/3sum/description/

给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

 
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // 1. 有序化处理
        sort(nums.begin(), nums.end());

        // 2. 使用固定一个数，吧问题转换成：两数之和为s的问题
        int size = nums.size();
        for(int i = 0; i<size;){
            if(nums[i] > 0) return result;      // 优化处理：和为零一定要存在非正数
            // 双指针[双边向中]
            int left = i + 1, right = size-1, target = -nums[i];
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum > target) right--;
                else if(sum < target) left++;
                else{
                    // 进行一次结果存储，并让指针向中移动一次！
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++,right--;
                    // 去重！！！
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
            i++;
            while(i < size && nums[i] == nums[i-1]) i++;

        }
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         sort(nums.begin(),nums.end());          // 有序化处理
//         for(int i = 0;i<nums.size();i++){
//             if(nums[i] > 0) return result;      // 首元素大于零，求和必不为零
//             if(i>0 && nums[i] == nums[i-1]) continue;   
//             // 设置双指针
//             int left = i + 1;
//             int right = nums.size()-1;
//             while(right > left){
//                 if(nums[i] + nums[left] + nums[right] > 0) right--;     // 求和偏大右数减小（右指针左移）
//                 else if(nums[i] + nums[left] + nums[right] < 0) left++; // 求和偏小左数增加（左指针右移）
//                 else{
//                     result.push_back(vector<int>{nums[i], nums[left], nums[right]});
//                     while(right > left && nums[right] == nums[right-1]) right--;
//                     while(right > left && nums[left] == nums[left+1]) left++;
//                     right--,left++;
//                 }
//             }

//         }
//         return result;
//     }
// };