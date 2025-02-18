/*
Question: You will be given an undirected graph as input. You need to tell the number of components in this graph.
Sample Input 1

6 5
0 1
0 2
0 3
2 3
4 5

Sample Output 1

2

Sample Input 2 

9 7
0 1
0 2
0 3
2 3
4 5
6 8
7 6
Sample Input 2

3

Sample Input 3

7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6

Sample Output 3

1

Sample Input 4

10 5
1 2
2 3
1 3
4 0
5 6
Sample Output 4

6 
(Because 7 8 and 9 nodes are not connected, but they are also components)



*/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<int>adjList[1005];
bool vis[1005];

void dfs(int src) {
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
    
    for(int i =0; i < v;i++) {
        if(vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}
