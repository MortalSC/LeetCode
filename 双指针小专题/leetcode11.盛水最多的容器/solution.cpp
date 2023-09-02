/*
题目描述：
https://leetcode.cn/problems/container-with-most-water/description/

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。


示例 1：
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针算法 + 单调性
        int left = 0, right = height.size()-1;
        int maxarea = 0;
        while(left <= right){
            int tempv = min(height[left],height[right])*(right-left);
            maxarea = max(maxarea, tempv);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxarea;
    }
};

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         // 暴力迭代法（顺向暴力双指针）：超出时间限制
//         int left = 0, right = 0;
//         int maxarea = 0;
//         for(int i = left;i<height.size();i++){
//             for(right = i+1;right<height.size();right++ ){
//                 int area = (right - i)*(min(height[i], height[right]));
//                 if(area > maxarea) maxarea = area;
//             }
//         }

//         return maxarea;
//     }
// };