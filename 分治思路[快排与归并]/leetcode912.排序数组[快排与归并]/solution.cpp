/*
问题描述：
https://leetcode.cn/problems/sort-an-array

给你一个整数数组 nums，请你将该数组升序排列。

示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]


提示：
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
*/

#include <bits/stdc++.h>
using namespace std;

/* 归并排序：先切分，再合并 */
class Solution
{
    int temp[50010];            // 全局辅助数组
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return; // 数组中只有一个或没有元素就不必排序了！
        
        // 获取中间值作为分割点
        int mid = (left + right) >> 1;

        // 分治：切分
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1,right);

        // 合并
        // 升序
        int p1 = left, p2 = mid + 1, cur = 0;
        while(p1 <= mid && p2 <= right){
            // 合并两个有序数组：升序：调小入组
            temp[cur++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
        }
        // 兜底
        while(p1 <= mid) temp[cur++] = nums[p1++];
        while(p2 <= right) temp[cur++] = nums[p2++];

        // 数据回填
        for(int i = left; i <= right; i++){
            nums[i] = temp[i-left];             // i-left：是用于临时数组数据填写时：从 cur = 0 开始！
        }
    }   
};

/* 快速排序：数组三分思路 */
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        // 设置一个随机数种子，用于在三分数组中的等概率取值
        srand(0);
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void qsort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return; // 数组中只有一个或没有元素就不必排序了！

        int key = getRand(nums, l, r); // 等概率获取取用中的随机值

        // 初始化处理边界
        int left = l - 1, right = r + 1, cur = l;
        while (cur < right)
        {
            if (nums[cur] < key)
                swap(nums[++left], nums[cur++]);
            else if (nums[cur] == key)
                cur++;
            else
                swap(nums[--right], nums[cur]);
            // 注意：和右边的数值交换时，交换过来的值是未探索区域的值！！！
        }

        // 递归处理
        qsort(nums, l, left);
        qsort(nums, right, r);
    }

    int getRand(vector<int> &nums, int left, int right)
    {
        return nums[rand() % (right - left + 1) + left];
    }
};