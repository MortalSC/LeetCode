/*
问题描述：
https://leetcode.cn/problems/happy-number/description/

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例 1：
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：
输入：n = 2
输出：false
*/

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n){
        // 拓展思路：联想链表成环！
        // 题意：然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
        int slow = n, fast = getSum(n);
        while(slow != fast){
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }
        
        return slow == 1;
    }

    // bool isHappy(int n) {
    //     // 实质上本题就是判断给出的数按照题设要求是否会出现死循环（或者说是重复数！！！）
    //     // 在一个集合中快速判断是否存在某个数是否存在 => 哈希表
    //     unordered_set<int> result;      // 构造查询表

    //     while(1){
    //         int sum = getSum(n);        // 获取结果
    //         if(sum == 1) return true;   // 如果是 1，则为快乐数

    //         // 否则判断这个数是否重复出现！！！
    //         if(result.find(sum) != result.end()){       // 重复
    //             return false;
    //         }else{                                      // 不重复：数据入表
    //             result.insert(sum);
    //         }
    //         n = sum;

    //     }
    // }
};