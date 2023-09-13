/*
问题描述：
https://leetcode.cn/problems/peak-index-in-a-mountain-array/

符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，
返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。


示例 1：
输入：arr = [0,1,0]
输出：1

示例 2：
输入：arr = [0,2,1,0]
输出：1

示例 3：
输入：arr = [0,10,5,2]
输出：1


提示：
3 <= arr.length <= 10^5
0 <= arr[i] <= 10^6
题目数据保证 arr 是一个山脉数组
*/

/*
    思路：
        山脉数组的二段性：峰值及其左侧一定时递增序列，右侧是递减序列
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 1, right = arr.size() - 2;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1]) // 在递增区间！
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};