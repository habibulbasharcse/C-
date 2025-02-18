#include <bits/stdc++.h>
using namespace std;

vector<int>adjList[1005];
bool vis[1005];

void dfs(int src) {
    cout << src << " "; 
    vis[src] = true;
    
    for(int child : adjList[src]) {
        if(!vis[child]) {
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
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    cout << endl;
    for(int i = 0; i < v;i++) {
        if(vis[i] == false) {
            dfs(i);
            cnt++;
            cout << endl;
        }
    }
    
    cout << cnt;
    
    
    

    return 0;
}
