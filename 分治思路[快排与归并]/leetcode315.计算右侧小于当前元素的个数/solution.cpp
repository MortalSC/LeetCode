/*
问题描述：
https://leetcode.cn/problems/count-of-smaller-numbers-after-self/

给你一个整数数组 nums ，按要求返回一个新数组 counts 。
数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例 1：
输入：nums = [5,2,6,1]
输出：[2,1,1,0]
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素

示例 2：
输入：nums = [-1]
输出：[0]

示例 3：
输入：nums = [-1,-1]
输出：[0,0]


提示：

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ret; // 记录结果
    vector<int> idx; // 索引
    int tempNum[500010];
    int tempIdx[500010];

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int size = nums.size();
        ret.resize(size);
        idx.resize(size);

        for (int i = 0; i < size; i++)
            idx[i] = i; // 索引下标初始化
        mergeSort(nums, 0, size - 1);
        return ret;
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int mid = (left + right) >> 1;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int p1 = left, p2 = mid + 1, cur = 0;
        while (cur < right)
        {
            if (nums[p1] <= nums[p2])
            {
                tempNum[cur] = nums[p2];
                tempIdx[cur++] = idx[p2++];
            }
            else
            {
                ret[idx[p1]] = right - p2 + 1;
                tempNum[cur] = nums[p1];
                tempIdx[cur++] = idx[p1++];
            }
        }

        while (p1 <= mid)
        {
            tempNum[cur] = nums[p1];
            tempIdx[cur++] = idx[p1++];
        }
        while (p2 <= right)
        {
            tempNum[cur] = nums[p2];
            tempIdx[cur++] = idx[p2++];
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = tempNum[i - left];
            idx[i] = tempIdx[i - left];
        }
    }
};