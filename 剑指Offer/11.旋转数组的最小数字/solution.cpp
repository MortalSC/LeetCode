/*
题目描述：
https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。  

注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

 

示例 1：

输入：numbers = [3,4,5,1,2]
输出：1
示例 2：

输入：numbers = [2,2,2,0,1]
输出：0
*/

#include <vector>
#include <climits>
using namespace std;
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberInRotateArray(vector<int>& nums) {
        // write code here

        // 二分法【版本二】
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        // 左闭右闭区间
        while (left < right) {
            mid = left + (right - left) / 2;
            // 判断是否在右边
            if (nums[mid] > nums[right]) {
                // 在右边
                left = mid + 1;
            } else if (nums[mid] == nums[right]) {
                right--;
            } else {
                right = mid;
            }
        }
        return nums[left];



        // 二分法【版本一】
        // 特性：序列中一定存在一个临界值使得存在非 0 次旋转的序列
        // 左边所有值大于右边所有值！
        // 使用二分法时，
        // 如果：中间值 > 左端点 => 说明左半部分是非递减的！目标在右侧
        // 如果：中间值 > 右端点 => 说明右半部分是非递减的！（此时可能就是目标值）
        // 左闭右闭区间！
        // int left = 0, right = nums.size() - 1;
        // int mid = 0;
        // while (nums[left] >= nums[right]) {
        //     // 尾区间判断
        //     if (right == left + 1) {
        //         mid = right;
        //         break;
        //     }

        //     // 特殊情况：大多数元素相同： 1 0 1 1 1
        //     if (nums[left] == nums[right] && nums[left] == nums[mid]) {
        //         for(int i = 0;i<nums.size()-1;i++){
        //             if(nums[i] > nums[i+1]) return nums[i+1];
        //         }
        //         return nums[0];
        //     }


        //     // 找到中间点
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] >= nums[left]) {
        //         left = mid;
        //     } else {
        //         right = mid;
        //     }
        // }
        // return nums[mid];


        // 特点：原序列一定是非递减的！
        // 旋转序列：一定会打破这种规律
        // 效率与旋转的深度挂钩！
        // for(int i = 0;i<nums.size()-1;i++){
        //     if(nums[i] > nums[i+1]) return nums[i+1];
        // }
        // return nums[0];

        // 管他三七二十一：暴力遍历！
        // int minval = INT_MAX;
        // for(int i = 0;i<nums.size();i++){
        //     minval = min(minval, nums[i]);
        // }
        // return minval;
    }
};