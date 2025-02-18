/*
Question: You will be given an undirected graph as input. You need to tell the number of nodes in each component in ascending order.
Sample Input
Sample Output
6 5
0 1
0 2
0 3
2 3
4 5
2 4
9 7
0 1
0 2
0 3
2 3
4 5
6 8
7 6
2 3 4


7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6
7
10 5
1 2
2 3
1 3
4 0
5 6
1 1 1 2 2 3
(Because 7 8 and 9 nodes are not connected, but they are also components)


*/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int cnt1 = 0;

vector<int>adjList[1005];
bool vis[1005];

void dfs(int src) {
    vis[src] = false;
    cnt1++;
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
    int arr[v];
    memset(arr,0,sizeof(arr));
    for(int i =0; i < v;i++) {
        if(vis[i]) {
            dfs(i);
            cnt++;
            arr[i] = cnt1;
        }else {
            cnt1 = 0;
        }
        
    }
    
    sort(arr, arr + v);
    for(int i : arr) {
        if(i != 0) 
            cout << i << " ";
    }

    return 0;
}
