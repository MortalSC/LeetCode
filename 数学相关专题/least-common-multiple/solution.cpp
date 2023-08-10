/**
 * 问题描述：
 * 求两个数的最小公倍数，两个数的最小公倍数为：能被这两个数同时整除的最小的数。
 *
 */

#include <iostream>
using namespace std;
// 方法一：暴力破解法

#if 0

int main()
{

    int a, b;
    while(cin >> a >> b){
        int ret = max(a,b);         // 取较大值
        while(true){
            if(ret % a == 0 || ret % b == 0){
                break;
            }
            ret++;
        }
        cout << ret << endl;
    }

    return 0;
}
#endif

// 方法二：特殊优化方法：最小公倍数 = 两数之积 / 最小公约数
// 求最小公约数方法：辗转相除法

int gcb(int n, int m)
{
    if (m == 0)
        return n;
    else
        return gcb(m, n % m);
    // 另一种写法
    /*
    int c;
    while(c = a % b){
        a = b;
        b = c;
    }
    return b;
    */
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a * b / gcb(a, b) << endl;
    }
    
}