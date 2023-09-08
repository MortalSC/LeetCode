/*
问题描述：
https://leetcode.cn/problems/find-all-anagrams-in-a-string

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

 示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

提示:
1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/

/*
思路一：构造出 p 字符串组成的字符的全排列，再去 s 查找。

思路二：滑动窗口（哈希表辅助）：通过对有效字符的计数来解决s的子串与s的字符全排列匹配问题
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // 两个哈希表
        int map1[26] = {0};
        int map2[26] = {0};
        // 构造 p 中字符的映射参考
        for (char ch : p)
            map1[ch - 'a']++;
        // 结果存储
        vector<int> res;

        int psize = p.size(); // p 的长度
        int cnt = 0;          // 记录有效字符个数

        // 合法结果标准：长度相同，有效字符个数相同

        // 滑动窗口
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            char in = s[right]; // 记录待插入字符
            map2[in - 'a']++;   // 字符插入

            // 合法字符判断
            if (map2[in - 'a'] <= map1[in - 'a'])
            {
                cnt++;
            }

            // 合法长度判断（不大于p的长度），相当于维护定长窗口
            if (right - left + 1 > psize)
            {
                // 不合法：需要删除最左端的字符
                char out = s[left++];           // 记录字符，并移动窗口
                // 如果是合法字符的更新
                if(map2[out-'a'] <= map1[out-'a']) cnt--;
            }

            if(psize == cnt) res.push_back(left);
        }
        return res;
    }
};