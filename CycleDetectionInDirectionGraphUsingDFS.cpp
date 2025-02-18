#include<bits/stdc++.h>
using namespace std;
vector<int>adjList[105];
bool vis[105];
bool pathVis[105];
bool cycle = false;

void dfs(int src) {
    vis[src] = true;
    pathVis[src] = true;
    
    for(int child : adjList[src]) {
        if(vis[child] && pathVis[child]) {
            cycle = true;
        }
        
        if(!vis[child]) {
            dfs(child);
        }
    }
    pathVis[src] = false;
}
int main() {
    int v,e;
    
    cin >> v >> e;
    
    while(e--) {
        int a,b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    
    memset(vis,false,sizeof(vis));
    memset(pathVis,false,sizeof(pathVis));
    
    dfs(0);
    
    if(cycle) cout << "Cycle Detection";
    else cout << "No Cycle";
    
    
}S
