/*
问题描述：
https://leetcode.cn/problems/move-zeroes/description/

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 区间式规划法（双指针）
        /*
            dest：始终记录到已处理的非零元素的最后一个位置
            cur：指向探查位置！
        */
        for(int cur = 0, dest = -1; cur < nums.size() ;cur++){
            if(nums[cur]){
                // 当前探查元素非零！则交换元素
                swap(nums[++dest],nums[cur]);
            }
        }
        /*
            该方法的过程中会存在 3 个区间：
            [0, dest]：已处理的区间
            [dest+1, cur-1]：零元素区间
            [cur+1, nums.size()-1]：待处理区间
        */
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int left = 0, right = 0, size = nums.size();
//         while(right < size){
//             if(nums[right]){
//                 swap(nums[left],nums[right]);
//                 left++;
//             }
//         right++;
//         }
//     }
// };


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int i = 0,j = 0;
//         for( i = 0;i<nums.size();i++){
//             if(nums[i] != 0){
//                 int temp = nums[i];
//                 nums[i] = nums[j];
//                 nums[j++] = temp;
//             }
//         }
//     }
// };


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int j = 0;
//         for(int i = 0;i<nums.size();i++){
//             if(nums[i] != 0){
//                 nums[j++] = nums[i];
//             }
//         }
//         for(;j<nums.size();j++){
//             nums[j] = 0;
//         }
//     }
// };