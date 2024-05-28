/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start

#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (int i = 0; i < n; i++)
        {
            int x = times[i][0] - 1;
            int y = times[i][1] - 1;
            int z = times[i][2];

            g[x][y] = z;
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;

        vector<bool> used(n, false);

        for(int i = 0; i < n; i++)
        {
            int x = -1;
            for(int y = 0; y < n; y++)
            {
                if(!used[y] && (x == -1 || dist[y] < dist[x]))
                {
                    x = y;
                }
            }

            used[x] = true;
            
            for(int j = 0; j < n; j++)
            {
                dist[j] = min(dist[j], dist[x] + g[x][j]);
            }
        }

        int res = *max_element(dist.begin(), dist.end());
        return res == inf ? -1 : res;
    }
};
// @lc code=end

