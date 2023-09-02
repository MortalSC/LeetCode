/*
题目描述：
https://leetcode.cn/problems/valid-triangle-number/description/

给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。

示例 1:
输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3

示例 2:
输入: nums = [4,2,3,4]
输出: 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 有序化处理
        sort(nums.begin(), nums.end());
        // 固定最大值最为第三边
        int ret = 0;
        for(int i = nums.size()-1; i >= 2; i--){
            // 双指针 + 单调性
            int left = 0, right = i-1;
            while(left < right){
                // 左右定点计算！若大于第三边，则定点范围内的所有值都可组成三角形！
                if(nums[left] + nums[right] > nums[i]){
                    ret += right - left;
                    right--;
                }else{
                    left++;
                }
            }
        }
        return ret;
    }
};