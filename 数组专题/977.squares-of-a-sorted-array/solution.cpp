/*
问题描述：https://leetcode.cn/problems/squares-of-a-sorted-array/
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 双指针：首尾标记
        int n = nums.size();
        vector<int> result(n);      // 初始化数组大小
        int i = 0, j = n-1, p = n-1;// 指针指向！其中，p指针指向填充位置！
        while( i<=j ){
            if(nums[i]*nums[i] >= nums[j]*nums[j])
                result[p] = nums[i]*nums[i],i++;
            else result[p] = nums[j]*nums[j],j--; 
            --p;
        }
        return result;
    }
};


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 暴力法：直接先进行元素平方处理，在排序即可
        for(int i = 0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};