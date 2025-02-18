/*
Question: You will be given an undirected graph which will be connected as input. Then you will be given a level L. You need to print the node values at level L in descending order. The source will be 0 always.

Sample Input1

3 2
0 1
0 2
1

Sample Output1

2 1

Sample Input 2

6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
1
Sample Output 2

3 2 1

Sample Input 3

6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
2

Sample Output 3

5 4



*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
vector<int>v;

void bfs(int src,int lvl) {
    queue<int>q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        int l = 0;
        if(level[par] == lvl) {
            v.push_back(par);
        }
        
        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                l++;
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
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    int lvl;
    cin >>lvl;
    bfs(0,lvl);
    for(int i = v.size() -1; i >= 0;i-- ) {
        cout << v[i] << " ";
    }

    
    return 0;
}
