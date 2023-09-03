/*
问题描述：
https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/

题⽬描述：
输⼊⼀个递增排序的数组和⼀个数字 s ，在数组中查找两个数，使得它们的和正好是 s 。如果有多
对数字的和等于 s ，则输出任意⼀对即可。

⽰例 1：
输⼊： nums = [2,7,11,15], target = 9
输出： [2,7] 或者 [7,2]
*/

#include <vector>
using namespace std;

// 双指针法
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return {nums[left], nums[right]};
        }
        // 照顾编译器
        return {-1, -1};
    }
};

// 暴力法
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        { // 第⼀层循环从前往后列举第⼀个数
            for (int j = i + 1; j < n; j++)
            {                                    // 第⼆层循环从 i 位置之后列举第⼆个数
                if (nums[i] + nums[j] == target) // 两个数的和等于⽬标值，说明我们已经找到结果了
                    return {nums[i], nums[j]};
            }
        }
        return {-1, -1};
    }
};
