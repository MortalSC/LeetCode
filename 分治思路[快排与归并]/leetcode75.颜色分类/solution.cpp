/*
问题描述：
https://leetcode.cn/problems/sort-colors

给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。
 

示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

示例 2：
输入：nums = [2,0,1]
输出：[0,1,2]
 

提示：
n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2
*/

/*
    解法：三指针三分数组：左右向中填写特定数据，中间指针否则探索。
    三指针：
        left：始终指向左边区域的结束点
        right：始终指向右边区域的起始点
        cur：探索指针
    三分数组实现的结果：[0,left] [left+1, right-1] [right, nums.size()-1]
        对于升序一定有：左边区域的值小于中间区域的值！
                右边区域的值一定大于中间区域的值！
                中间区域的值都相等！！！
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size(), cur = 0;
        while(cur < right){
            if(nums[cur] == 0) swap(nums[++left],nums[cur++]);
            else if(nums[cur] > 1) swap(nums[--right],nums[cur]);
            else cur++;
        }
    }
};