/*
问题描述：
https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5

限制：
0 <= 数组长度 <= 50000
*/

/*
思路：
    二分化两个有序区间！分别从中选出一个值作比较！
    如：[1,2,6,8] [3,4,5,9]
    选出：6（左）、5（右）=> 显然满足逆序对规则
    观察可发现：5 之前的数同样可以组成逆序对！
    6（左）、5（右）=> 逆序对个数：idx(6)~idx(8)：mid - p1 + 1
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

        // 记录结果
        int ret = 0;
        int mid = (left + right) >> 1;
        ret += mergeSort(nums, left, mid);
        ret += mergeSort(nums, mid + 1, right);

        // 归并（升序情形）
        int p1 = left, p2 = mid + 1, cur = 0;
        while (p1 <= mid && p2 <= right)
        {
            if (nums[p1] <= nums[p2]){           // 不满足逆序数对
                temp[cur++] = nums[p1++];
            }else{
                ret += mid - p1 + 1;
                temp[cur++] = nums[p2++];
            }
        }

        // 兜底
        while(p1 <= mid) temp[cur++] = nums[p1++];
        while(p2 <= right) temp[cur++] = nums[p2++];

        for(int i = left; i <= right; i++){
            nums[i] = temp[i-left];
        }
        return ret;
    }
};
