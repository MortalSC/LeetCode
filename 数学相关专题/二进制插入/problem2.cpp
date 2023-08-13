/*
问题描述：https://leetcode.cn/problems/insert-into-bits-lcci/

给定两个整型数字 N 与 M，以及表示比特位置的 i 与 j（i <= j，且从 0 位开始计算）。

编写一种方法，使 M 对应的二进制数字插入 N 对应的二进制数字的第 i ~ j 位区域，不足之处用 0 补齐。具体插入过程如图所示。

题目保证从 i 位到 j 位足以容纳 M， 例如： M = 10011，则 i～j 区域至少可容纳 5 位。
*/


class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        // 先对 N 中的 i ~ j 位置零
        for(int k = i; k <= j; k++){
            /*
                说明：二进制某位的置零操作！
                 1：0000 0001
            1 << 3：0000 1000
         ~(1 << 3)：1111 0111
            x & 0 ：0    
            */
            N &= ~(1 << k);
        }

        // 再将M左移i位，使之对齐上一步中N置零的位，直接相加即可。
        return N | (M << i);
    }
};

