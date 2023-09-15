/*
问题描述：
https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/

输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/

/*
思路：
    三分数组快排，判断k在哪个区域！
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &nums, int k)
    {
        srand(0);
        qsort(nums, 0, nums.size() - 1, k);
        return {nums.begin(), nums.begin() + k};
    }

    void qsort(vector<int> &nums, int l, int r, int k)
    {
        if (l >= r)
            return;
        int key = nums[rand() % (r - l + 1) + l];
        int left = l - 1, right = r + 1, cur = l;
        while (cur < right)
        {
            if (nums[cur] < key) swap(nums[++left], nums[cur++]);
            else if (nums[cur] > key) swap(nums[--right], nums[cur]);
            else cur++;
        }

        // 判断属于哪个区域
        int a = left - l + 1, b = right - 1 - (left + 1) + 1;
        if(a > k) qsort(nums,l,left,k);
        else if(a+b >= k) return ;          // 中间区域的值都相等！
        else qsort(nums, right, r, k-a-b);
    }
};