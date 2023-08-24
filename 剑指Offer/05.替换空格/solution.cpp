/*
问题描述
https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

限制：0 <= s 的长度 <= 10000
*/

#include <iostream>
#include <string>
using namespace std;

// 力扣
class Solution
{
public:
    string replaceSpace(string s)
    {
        // 双指针法从后往前（原地修改）：先扩容，再填充
        int count = 0; // 统计空格个数
        int oldsize = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                count++;
        }
        // 扩展原字符串大小：1（' '） => 3（%20）
        s.resize(s.size() + 2 * count);
        for (int i = s.size() - 1, j = oldsize - 1; j < i; i--, j--)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            }
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

class Solution
{
public:
    string replaceSpace(string s)
    {
        // 额外空间法
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            str = (s[i] == ' ' ? str + "%20" : str + s[i]);
            // str += (s[i] == ' '?"%20":s[i]);     // 易错点：类型问题
        }
        return str;
    }
};

// 牛客
// 双指针法从后往前（原地修改）：先扩容，再填充
#include <cctype>
class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        int cnt = 0;
        char *temp_str = str;

        // 统计空格个数
        while (*temp_str)
        {
            if (*temp_str == ' ')
                cnt++;
            temp_str++;
        }

        // 从后先前填充！
        char *oldstr = str + length; // 指向 \0
        char *newstr = str + length + cnt * 2;
        while (oldstr >= str && newstr >= str)
        {
            // 判断是否为空格
            if (!isspace(*oldstr))
            {
                // 不是空格，填充字符
                *newstr = *oldstr;
                newstr--, oldstr--;
            }
            else
            {
                // 是空格
                oldstr--;
                *newstr-- = '0';
                *newstr-- = '2';
                *newstr-- = '%';
            }
        }
    }
};
