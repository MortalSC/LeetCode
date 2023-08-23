/*
题目描述：
https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
*/


#include <vector>
using namespace std;

// 双指针法
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left <= right ){
            while(left < right && nums[left] % 2 == 1) left++;
            while(left < right && nums[right] % 2 == 0) right--;
            if(left < right) swap(nums[left],nums[right]);
            left++,right--;
        }
        return nums;
    }
};