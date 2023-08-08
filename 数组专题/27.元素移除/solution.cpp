class Solution {
public:
    // 双指针思路：快慢指针【覆盖法】
    int removeElement(vector<int>& nums, int val) {
        int j = 0;                          
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != val){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};


class Solution {
public:
    // 双指针思路：前后指针法
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            // 思路核心后面元素向前覆盖（本题中没有不变序要求）
            while( left <= right && nums[left] != val ){
                left++;     // 找到序列中最左边的目标值
            }
            while( left <= right && nums[right] == val ){
                right--;    // 找到序列中最右边的非目标值
            }
            if(left<= right){
                nums[left++] = nums[right--];
            }
        }
        return left;
    }
};