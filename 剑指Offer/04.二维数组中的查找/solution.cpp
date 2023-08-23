/*
题目描述
https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e
https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 二分法
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int mid = left + (right - left) /2;
            if(numbers[mid] > numbers[right]){
                // 目标在右边
                left = mid + 1;
            }else if(numbers[mid] == numbers[right]){
                right--;
            }else{
                // 目标在左边
                // 由于可能存在该值就是最小的情况，所以区间更新为：
                right = mid;
            }
        }
        return numbers[left];
    }
};

// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         // 方法一：暴力遍历法
//         int minval = INT_MAX;
//         for(int i = 0; i < numbers.size() ;i ++){
//             minval = min(minval, numbers[i]);
//         }
//         return minval;
//     }
// };