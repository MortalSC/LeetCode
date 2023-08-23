/*
题目描述
https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593
描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include <vector>
using namespace std;
class Solution {
  public:
    void reOrderArray(vector<int>& array) {
        // 只做奇偶前后分布
        // int left = 0, right = array.size() - 1;
        // while (left <= right) {
        //     while (array[left] % 2 == 1) left++;
        //     while(array[right] % 2 == 0) right--;
        //     swap(array[left++], array[right--]);
        // }
        // for(auto e : array){
        //     cout << e << ' ';
        // }

        // 方法二：插入排序思路
        int k = 0;              // k 标识当前序列前 k 个是奇数
        for(int i = 0; i< array.size() ;i++){
            if(array[i] & 1 ){
                // 当前值为奇数
                int temp = array[i];
                int j = i;              // 记录插入位置
                while(j > k){
                    array[j] = array[j-1];
                    j--;
                }
                array[k++] = temp;
            }
        }

        // 方法一：借助队列法
        // queue<int> q1;
        // queue<int> q2;

        // for (auto e : array) {
        //     if (e % 2 == 1) q1.push(e);
        //     else q2.push(e);
        // }
        // int pos = 0;
        // while (!q1.empty()) {
        //     array[pos++] = q1.front();
        //     q1.pop();
        // }
        // while (!q2.empty()) {
        //     array[pos++] = q2.front();
        //     q2.pop();
        // }
    }
};