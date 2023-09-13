/*
问题描述：
https://leetcode.cn/problems/que-shi-de-shu-zi-lcof

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:
输入: [0,1,3]
输出: 2

示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 
限制：
1 <= 数组长度 <= 10000
*/

/*
    思路：
        1. 直接遍历法
        2. 高斯求和再减法
        3. 哈希桶映射法

        二分法！！！
        如果是合法值，必然有：index == val；
        合法值一定再左侧！经过异常点导致后面全部异常！
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == mid) left = mid + 1;
            else right = mid;
        }
        // left + (right - left) / 2：的mid指向一定是二段区偏左侧，到临界处时，可能正好指向合法区间的末端
        if(nums[left] == left) left += 1;
        return left;
    }
};