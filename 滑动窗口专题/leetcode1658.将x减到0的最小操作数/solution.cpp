/*
问题描述：


给你一个整数数组 nums 和一个整数 x 。
每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。
如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

示例 1：

输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
示例 2：

输入：nums = [5,6,7,8,9], x = 4
输出：-1
示例 3：

输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
*/

/*
思路：
    由于每次可以从左右边界删除值，以达到题设目的！正向操作困难！
    但是可以注意到：每次只能从边界处理！那么中间部分一定连续！
*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for(auto e : nums) sum += e;            // 逆向思维：求最长子数组和
        int target = sum - x;                   // 和
        if(target < 0)return -1;                // 若为负值，即不可能加和为 0
        int temp = 0;                           // 窗口内数据和
        int res = -1;
        for(int left = 0 , right = 0;right < nums.size(); right++){
            // 进入窗口
            temp += nums[right];
            // 判断是否合法
            while(temp > target){
                // 出窗口
                temp -= nums[left++];
            }
            // 更新窗口长度（当且仅当符合差值才统计长度）
            if(temp == target)
                res = max(res, right - left + 1);
        }
        if(res == -1) return -1;
        else return nums.size() - res;
    }
};