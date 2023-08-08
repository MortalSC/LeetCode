/* 
704. 二分查找
问题描述：
    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
    写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */


/*
    二分查找算法（双指针）：两个模型
    1. 左闭右开：
        区间大小 = 右 - 左
        左右指针不可能相遇【合法范围内！】
    2. 左闭右闭：    
        区间大小 = 右 - 左 + 1
        左右指针可能指向同一个值【合法范围内】
*/


// 1. 左闭右开：
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (( right - left ) / 2) ;     // 写法：防止溢出
            if(target < nums[mid]){
                // 说明目标可能在左！
                // mid 不是目标即为新区间的尾部的下一个位置！
                right = mid;                
            }else if(target > nums[mid]){
                // 说明目标可能在右！
                // mid 不是目标即为原区间 mid 的下一个位置是新区间的开始！！
                left = mid + 1;             
            }else return mid;
        }
        return -1;
    }
};

// 1. 左闭右闭：
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (( right - left ) / 2) ;     // 写法：防止溢出
            if(target < nums[mid]){
                // 说明目标可能在左！
                // mid 不是目标即为新区间的尾部是 mid 的前一个位置！
                right = mid - 1;                
            }else if(target > nums[mid]){
                // 说明目标可能在右！
                // mid 不是目标，即为 mid 的下一个位置是新区间的开始！！
                left = mid + 1;             
            }else return mid;
        }
        return -1;
    }
};