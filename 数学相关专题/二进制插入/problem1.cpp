/*
问题描述：https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490
描述
给定两个32位整数n和m，同时给定i和j，将m的二进制数位插入到n的二进制的第j到第i位,
保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1，其中二进制的位数从0开始由低到高。

测试样例：1024，19，2，6
返回：1100
*/

/*
    注意：由于题设保证了：n的第j到第i位均为零
    因此可以通过对 m 左移一定位数，和 n 按位或即可得到答案！

    提升：若不保证n的第j到第i位均为零，如problem2【https://leetcode.cn/problems/insert-into-bits-lcci/】
*/
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        return n | ( m << j);
        // return n + ( m << j);    // 由于 i ~ j 位都是 0，加法运算不进位！
    }
};