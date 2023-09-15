/*
问题描述：
https://leetcode.cn/problems/reverse-pairs/description/

给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
你需要返回给定数组中的重要翻转对的数量。

示例 1:
输入: [1,3,2,3,1]
输出: 2

示例 2:
输入: [2,4,3,5,1]
输出: 3

注意:
1.给定数组的长度不会超过50000。
2.输入数组中的所有数字都在32位整数的表示范围内。
*/

/*
思路：

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int temp[50010];
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return 0;
        int ret = 0;
        int mid = (left + right) >> 1;
        ret += mergeSort(nums, left, mid);
        ret += mergeSort(nums, mid + 1, right);
        int p1 = left, p2 = mid + 1, cur = 0;
        while (p1 <= mid)
        {
            while (p2 <= right && nums[p1] > nums[p2] * 2.0)
            {
                p2++;
            }
            if (p2 > right)
                break;
            ret += right - p2 + 1;
            p1++;
        }

        while (p1 <= mid)
            temp[cur++] = nums[p1++];
        while (p2 <= right)
            temp[cur++] = nums[p2++];

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i];
        }
        return ret;
    }
};