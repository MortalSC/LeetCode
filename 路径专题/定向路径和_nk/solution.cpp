/*
问题描述：（牛客）https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314
请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）从棋盘左上角出发沿着边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

注：沿棋盘格之间的边缘线行走【不可以对角线走】

数据范围： 1≤n,m≤8

输入描述：输入两个正整数n和m，用空格隔开。(1≤n,m≤8)

输出描述：输出一行结果

示例1
输入：2 2
输出：6
*/

#include <iostream>
using namespace std;

// 组合数学法：组合
/*
    思路：走到某个定点的路径如：N(i，j) 无非就是两种选择！(i-1，j) 或 (i，j-1)
    不管怎么走，总要从左上到右下，那么要向下走n次，向右走m次，总共也只走m+n次，
    那么方法数就是从这 m+n 次中选出 m 次向右走的方案，即C（m,m+n）【组合：m+n中选m次 / m+n中选n次】
*/
// 组合法
int getret(int n, int m)
{
    int ret = 0;
    int x = 1, y = 1;
    for (int i = 1; i <= n; i++)
    {
        x *= m + i;
        y *= i;
    }
    ret = x / y;
    return ret;
}

// 递归法
int pathnum(int n, int m)
{
    if (n == 0 || m == 0)
        return 1;
    return pathnum(n - 1, m) + pathnum(n, m - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << pathnum(n, m) << endl;

    return 0;
}