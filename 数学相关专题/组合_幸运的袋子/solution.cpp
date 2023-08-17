/*
问题描述：https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee
描述
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

输入描述：
第一行输入一个正整数n(n ≤ 1000) 第二行为n个数正整数xi(xi ≤ 1000)
输出描述：
输出可以产生的幸运的袋子数

示例1
输入：
3
1 1 1
输出：
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 顺序加和找可组合的方案
// 注意： a + b > a*b 的前提是一定有一个值为：1
// 采用深度优先来解决问题

// pos 标识组合的开始位置！
int GetRet(vector<int>& ret, int n, int pos, int sum, int mulit) {
    int cnt = 0;
    for (int i = pos; i < n; i++) {
        // 数据更新
        sum += ret[i];
        mulit *= ret[i];
        // 判断是否幸运
        if (sum > mulit) { // 幸运
            // 若当前幸运则深度优先【注意位置 + 1】
            cnt += 1 + GetRet(ret, n, i + 1, sum, mulit);
        } else if (ret[i] == 1 ) {
            cnt += GetRet(ret, n, i + 1, sum, mulit);
        } else {
            // 由于序列是有序的！如果当前值破坏了幸运条件，应该回溯！
            break;
        }
        // 回溯回来要数据更新
        sum -= ret[i];
        mulit /= ret[i];
        // 组合中不要重复的：需要去重处理
        while( i < n-1 && ret[i]==ret[i+1]){
            i++;
        }
    }
    return cnt;
}

int main() {
    int n;

    while (cin >> n) {
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            cin >> ret[i];
        }
        sort(ret.begin(), ret.end());
        cout << GetRet(ret, n, 0, 0, 1) << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")