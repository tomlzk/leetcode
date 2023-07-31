/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution
{
public:

    bool judgeit(string &temp)
    {
        int balance = 0;
        char c;
        for(char c : temp)
        {
            if(c == '(')
            {
                balance++;
            }
            else
            {
                balance--;
            }

            if(balance < 0)
            {
                return false;
            }
        }

        if(balance != 0)
        {
            return false;
        }

        return true;
    }

    void backsu(vector<string> &v, string &temp, int n)
    {
        if(temp.size() == 2*n)
        {
            if(judgeit(temp) == true)
            {
                v.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        backsu(v, temp, n);
        temp.pop_back();

        temp.push_back(')');
        backsu(v, temp, n);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        string temp;
        backsu(v, temp, n);
        return v;
    }
};
// @lc code=end
