/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start

#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    string simplifyPath(string path)
    {
        string result = "";
        vector<string> queue;
        for(int i = 0; i < path.size();)
        {

            string temp;
            if(path[i] == '/')
            {
                i++;
                if(path[i] == '.' && path[i + 1] == '/')
                {
                    i = i + 1;
                    continue;
                }
                
                if((path[i] == '.' && path[i + 1] == '.') && (i + 1 == path.size() - 1 || path[i + 2] == '/'))
                {
                    if(!queue.empty())
                    {
                        queue.pop_back();
                    }
                    i = i + 2;
                    continue;
                }

                while(i < path.size() && path[i] != '/')
                {
                    temp = temp + string(1, path[i]);
                    i++;
                }
                if(!temp.empty() && temp != "." && temp != "..")
                {
                    queue.push_back(temp);
                }
            }
        }
        if(queue.size() == 0)
        {
            return "/";
        }
        for(int i = 0; i < queue.size(); i++)
        {
            result = result + "/" + queue[i];
        }
        return result;
    }
};
// @lc code=end
