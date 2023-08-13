/*
题目描述
（leetcode）https://leetcode.cn/problems/max-consecutive-ones/
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

示例 1：

输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.

示例 2:

输入：nums = [1,0,1,1,0,1]
输出：2
================================================================================

（牛客）https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2

描述
求一个int类型数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

数据范围：数据组数：1≤t≤5 ，500000
 
1≤n≤500000 
进阶：时间复杂度：O(logn) ，空间复杂度：O(1) 

输入描述：
输入一个int类型数字

输出描述：
输出转成二进制之后连续1的个数

示例1
输入：200
输出：2

说明：200的二进制表示是11001000，最多有2个连续的1。
=================================================================================
拓展：要求扩大数据域，包含负数（32位下）！

注：关于左移右移的高位补值说明！
正数：高位补 0！
负数：高位补 1！

*/
#include<iostream>
#include <vector>
using namespace std;

// leetcode
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, temp = 0;
        for(auto e : nums)
        {
            if(e == 1){
                temp ++;
                cnt = max(cnt, temp);
            }
            else{
                temp = 0;
            }
        }
        return cnt;
    }
};

// 牛客
#include <iostream>
using namespace std;

int main() {

    int num;
    cin >> num;
    int maxcnt = 0, maxtmp = 0;

    // 该方案不能解决负数问题！
    // while(num){
    //     if(num & 1){
    //         maxtmp++;
    //         maxcnt = max(maxcnt, maxtmp);
    //     }else{
    //         maxtmp = 0;
    //     }
    //     num >>= 1;
    // }

    for (int i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            maxtmp++;
            maxcnt = max(maxcnt, maxtmp);
        } else {
            maxtmp = 0;
        }
        // num >>= 1;
    }

    cout << maxcnt << endl;
    return 0;
}