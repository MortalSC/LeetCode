/*
问题描述：https://leetcode.cn/problems/minimum-size-subarray-sum/

给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：

输入：target = 4, nums = [1,4,4]
输出：1

示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int res = INT32_MAX;
        int len = 0;            // 子数列长度
        int i =0;               // 子列起始位
        int sum = 0;
        for(int j = 0; j<nums.size() ;j++){
            sum += nums[j];
            while(sum >= target){       // 核心代码：当和符合要求时！移动左区间边界探索最小！
                len = j-i+1;            // 获取合法子数列长度【闭区间计算长度法】
                res = res > len ? len : res;
                sum -= nums[i++];          
                // 子列起始位长度调整，改写法规避了可能单次移动遇到负数引起的重复操作！
            }
        }
        return res == INT32_MAX?0:res;
    }
};


// 超时
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         // 双循环暴力法
//         int sum = 0;
//         int res = INT32_MAX;
//         int len = 0;
//         for(int i = 0;i<nums.size();i++){   // 设置子数组起始点
//             sum = 0;
//             for(int j = i;j<nums.size();j++){   // 探索子数组终点
//                 sum += nums[j];
//                 if(sum >= target){
//                     len = j-i+1;                // 子列长度【闭区间计算长度法】
//                     res = res > len?len:res;
//                     break;
//                 }
//             }
//         }
//         return res == INT32_MAX? 0:res;
//     }
// };