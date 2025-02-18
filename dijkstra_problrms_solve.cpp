/*  
    Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.

Examples:

Input: adj = [[[1, 9]], [[0, 9]]], src = 0
Output: [0, 9]
Explanation:

The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9.
Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
Output: [4, 3, 0]
Explanation:

For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So, the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 
*/



// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
 
    
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        vector<int> dis(adj.size(), INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0, src});
        
        dis[src] = 0;
        
        while(!pq.empty()) {
            pair<int,int> par = pq.top();
            pq.pop();
            
            int pd = par.first;
            int pn = par.second;
            
            for(auto child : adj[pn]) {
                int cn = child.first;
                int cd = child.second;
                
                if(pd+ cd < dis[cn]) {
                    dis[cn] = pd+cd;
                    pq.push({dis[cn],cn});
                }
            }
        }
        
        return dis;
    }
};
int main() {
    int v,e;
    cin >> v >> e;
    vector<vector<pair<int,int>>>adjList(v);
    
    while(e--) {
        int a,b,c;
        cin >> a>>b >> c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }
    
    Solution so;
    
    vector<int> result = so.dijkstra(adjList,0);
    
    for(int r : result) {
        cout << r << " ";
    }
    return 0;
}
