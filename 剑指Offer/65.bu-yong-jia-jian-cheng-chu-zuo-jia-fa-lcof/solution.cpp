/*
问题描述：
给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。

测试样例：
1,2
返回：3
*/

/*
    总体思路：转化成二进制的求和
    第一步：进制转换！（十 => 二）
    第二步：求和，注意进位！
    第三步：进制转换！（二 => 十）

    具体实现：
        二进制相加（获取不进位值）：异或（不同为一，相同为零！）
        记录进位（获取进位值）：与（都为一，才是一！） 后左移一位！
        反复操作：直到一方为：0，返回答案！
*/

#include <iostream>
using namespace std;

int getret(int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    int a = n ^ m;        // 获取二进制相加（只相加不进位）
    int b = (n & m) << 1; // 获取两数相加的进位！
    return getret(a, b);
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << getret(n, m) << endl;
    }

    return 0;
}


class Solution {
public:
    int add(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        int A = a ^ b;          // 获取二进制形式加法（不进位）
        int B = (a & b) << 1;   // 获取二进制形式加法所得的进位
        return add(A,B);
    }
};