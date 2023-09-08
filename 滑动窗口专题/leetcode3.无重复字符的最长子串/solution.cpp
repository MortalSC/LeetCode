/*
问题描述：
https://leetcode.cn/problems/longest-substring-without-repeating-characters

给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。s 由英文字母、数字、符号和空格组成

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口：哈希表辅助
        int res = 0;                        // 记录最长子串
        int hash[128] = {0};                // 记录字符出现的次数：当映射值等于 1，就说明重复了
        for(int left = 0, right = 0; right < s.size(); right++){
            hash[s[right]]++;               // 映射
            // 判断是否出现重复
            while(hash[s[right]] > 1){
                hash[s[left++]]--;          // 左边界移动并删除出现重复字符目标前的所有字符
            }
            // 更新长度
            res = max(res, right-left+1);
        }
        return res;
    }
};