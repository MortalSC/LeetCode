/*
题目描述：https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad
描述
输入一个正整数，计算它在二进制下的1的个数。
注意多组输入输出！！！！！！

数据范围： 0~2e32

输入描述：
输入一个整数

输出描述：
计算整数二进制中1的个数

示例1
输入：5
输出：2
说明：
5的二进制表示是101，有2个1   

示例2
输入：0
输出：0
*/

// 方法二：位运算的高校算法

#include <iostream>
using namespace std;

int main() {

    int cnt = 0;
    size_t val;
    while(cin>>val){
        cnt = 0;
        while(val){
            val &= val - 1;
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}

// 方法一：位运算的基本操作（本质还是遍历式判断！）
#include <iostream>
using namespace std;

int main() {

    int cnt = 0;
    size_t val;
    while(cin>>val){
        cnt = 0;
        while(val){
            if(val & 1) cnt++;
            val >>= 1;
        }
        cout << cnt << endl;
    }

    return 0;
}
