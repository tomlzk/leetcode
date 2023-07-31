/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;
        for(string temp : strs)
        {
            string now = temp;
            sort(now.begin(), now.end());
            // pair<string, string> s;
            // s.first = now;
            // s.second = temp;
            // m.push_back(s);
            m[now].emplace_back(temp);
        }

        vector<vector<string>> v;
        for(map<string, vector<string>>::iterator it = m.begin(); it != m.end() ; it++)
        {
            v.emplace_back(it->second);
        }
        return v;
    }
};
// @lc code=end
