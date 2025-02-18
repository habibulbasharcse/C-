#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[105];
bool vis[105];
bool cycle;
int parent[105];

void dfs(int src) {
    vis[src] = true;
     for(int child : adjList[src]) {
        if(vis[child] && parent[src] != child) {
             cycle = true;
        }
         
        if(!vis[child]) {
            parent[child] = src;
            dfs(child);
        }
     }
}

int main() {
    cycle = false;
    
    int v,e;
    cin >> v >> e;
    
    while(e--) {
        int a,b;
        cin >> a >> b;
        
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(parent,-1,sizeof(parent));
    memset(vis,false,sizeof(vis));
    for(int i = 0 ; i < v;i++) {
        if(!vis[i]) 
            dfs(i);
    }
    
    if(cycle) {
        cout << "Cycle";
    }else {
        cout << "No Cycle";
    }
    
    
}

