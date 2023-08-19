/*
问题描述：
https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof
https://leetcode.cn/problems/number-of-1-bits/

编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用 二进制补码 记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。
*/



#include <iostream>

/*
    思路：& ：都是一，才为一的特性：可以用于按位判断指定数值的二进制表示下的每位是否为：1
*/

// 方法二：位运算的高效用法（执行次数却决于 1 的个数！）
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            n &= n -1;
            cnt++;
        }
        return cnt;
    }
};



// 方法一：位运算的基本用法（本质还是在遍历：效率偏低）
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};