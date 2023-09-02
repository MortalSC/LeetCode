/*
题目描述：
https://leetcode.cn/problems/duplicate-zeros/description/

给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
示例 1：
输入：arr = [1,0,2,3,0,4,5,0]
输出：[1,0,0,2,3,0,0,4]
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]

示例 2：
输入：arr = [1,2,3]
输出：[1,2,3]
解释：调用函数后，输入的数组将被修改为：[1,2,3]
*/


#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // 1. 顺序遍历模拟找到最后一个有效元素位置
        int n = arr.size();
        int cur = 0, dest = -1; // dest 用于标识有效插入的位置
        while(cur < n){
            if(arr[cur]) dest++;
            else dest+=2;
            if(dest >= n-1) break;  // dest 到最后一个位置 / 越界说明结束！
            cur++;
        }

        if(dest == n){
            // 越界
            arr[n-1] = 0;
            cur--;
            dest-=2;
        }

        while(cur >= 0){
            if(arr[cur]){
                // 非零
                arr[dest--] = arr[cur--];
            }else{
                // 遇到 0
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }

    }
};