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
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    int src,dst;
    cin >> src >>dst;
    bfs(src);
    /*for(int i = 0; i < vertex;i++) {
        cout << i <<" -> " << level[i] << endl;
    }*/
    
    cout << level[dst];


    return 0;
}
