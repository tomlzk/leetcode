/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
class Graph {
public:
   private:
   const int inf = INT_MAX / 2;
    vector<vector<int>> g;
    int n = 0;
public:

    Graph(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        vector<vector<int>> temp(n, vector<int>(n, inf));
        for(int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            int z = edges[i][2];
            temp[x][y] = z;
        }

        g = temp;
    }
    
    void addEdge(vector<int> edge) 
    {
        int x = edge[0];
        int y = edge[1];
        int z = edge[2];
        g[x][y] = z;
    }
    
    int shortestPath(int node1, int node2) 
    {
        vector<int> dist(n, inf);
        dist[node1] = 0;

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

        return dist[node2] == inf ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end

