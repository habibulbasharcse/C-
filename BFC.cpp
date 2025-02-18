#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src) {
    queue<int>q;
    q.push(src);
    visited[src] = true;
    
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        
        cout << par << " ";
        
        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
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
    bfs(0);


    return 0;
}
