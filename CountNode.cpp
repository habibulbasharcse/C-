/*
Question: You will be given an undirected graph as input. Then you will be given a node N. You need to tell the number of nodes that can be visited from node N.

Sample Input 1
6 5
0 1
0 2
0 3
2 3
4 5
2

Sample Output 1

4

Sample Input 2
6 5
0 1
0 2
0 3
2 3
4 5
4

Sample Output 2
2

Sample Input 3

7 6
0 1
1 2
2 3
1 3
4 0
5 6
1

Sample Output 3

5



*/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<int>adjList[1005];
bool vis[1005];

void dfs(int src) {
    cnt++;
    vis[src] = false;
    
    for(int child : adjList[src]) {
        if(vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    int v,e;
    cin >> v >> e;
    
    while(e--) {
        int a,b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(vis,true,sizeof(vis));
    int node;
    cin >> node;
    dfs(node);
    cout << cnt;

    return 0;
}
