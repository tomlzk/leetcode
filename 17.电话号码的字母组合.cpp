/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> v;
        string mv;
        if(digits.empty())
        {
            return v;
        }
        map<char, string> m
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backstract(v, m, digits, 0, mv);
        return v;
    }

    void backstract(vector<string> &v, map<char, string> &m, string &digits, int index, string mv)
    {
        if(index == digits.length())
        {
            v.push_back(mv);
        }
        char digit = digits[index];
        string letters = m[digit];
        for(char c : letters)
        {
            mv.push_back(c);
            backstract(v, m, digits, index + 1, mv);
            mv.pop_back();
        }
    }
};
// @lc code=end
