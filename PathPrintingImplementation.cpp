#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];

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
                parent[child] = par;
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
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    int src,dst;
    cin >> src >>dst;
    bfs(src);
    
    cout << level[dst] << endl;
    int node = dst;
    vector<int> path;
    
    
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(),path.end());
    for(int x : path) {
        cout << x << " ";
    }
    
    
    

    return 0;
}
