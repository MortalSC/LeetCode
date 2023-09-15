/*
问题描述：
https://leetcode.cn/problems/kth-largest-element-in-an-array

给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。


示例 1:
输入: [3,2,1,5,6,4], k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
 
提示：
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

/*
思路：
    排序解决问题！
    为了效率最优，可以使用三分数组实现去指定的区间寻找第k个大的元素
    如：假设
        [0, left] [left+1, right-1] [right, nums.size()-1]
        记每个区间长度分别为：a、b、c
        （1）c >= k：=> 在 [right, nums.size()-1]
        （2）b+c >= c：=> 在 [left+1, right-1]
        （3）就是 [0, left] 中的第 k-b-c 个元素 
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(0);
        return qsort(nums, 0,nums.size()-1, k);
    }

    int qsort(vector<int>& nums, int l, int r, int k){
        if(l == r) return nums[l];

        int key = nums[rand()%(r-l+1)+l];

        int left = l-1, right = r+1, cur = l;       // 注意：cur 的起始点！
        while(cur < right){
            if(nums[cur] < key) swap(nums[++left], nums[cur++]);
            else if(nums[cur] > key) swap(nums[--right], nums[cur]);
            else cur++;
        }

        int c = r - right + 1, b = right - 1 -(left + 1) + 1;
        if(c >= k) return qsort(nums,right, r, k);
        else if( b+c >= k) return key;
        else return qsort(nums, l, left, k-b-c);
    }

    
};