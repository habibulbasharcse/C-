/*
Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, you will be given source S and destination D. You need to print the shortest distance between S and D. If there is no path from S to D, print -1.

Sample Input 1
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0
Sample Output1
2
3
3
2
2
0

Sample Input 2
7 5
0 1
0 2
4 5
4 6
5 7
3
0 4
5 1
1 3
Sample Output 2
-1
-1
-1

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];

void bfs(int src) {
    queue<int>q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        
        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
            }
        }
        
    }
}

int main() {
    int vertex,edge;
    cin >> vertex >> edge;
    
    while(edge--) {
        int a,b;
        
        cin>> a >> b;
        
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--) {
        int src,dst;
        cin >> src >>dst;
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));
        bfs(src);
        cout << level[dst]<< endl;

    }
    return 0;
}
