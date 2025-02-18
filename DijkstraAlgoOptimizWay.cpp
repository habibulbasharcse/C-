#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adjList[105];
int dis[105];

void dijkstra (int src) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;
    
    while(!pq.empty()) {
        pair<int,int> par = pq.top();
        pq.pop();
        
        int parDis = par.first;
        int parNode = par.second;;
        
        for(auto child : adjList[parNode]) {
            int childNode = child.first;
            int childDis = child.second;
            
            if(parDis+childDis  < dis[childNode]) {
                dis[childNode] = parDis+childDis;
                pq.push({dis[childNode],childNode});
            }
        }
    }
    
}


int main() {
    int v,e;
    cin >> v >> e;
    
    while(e--) {
        int a,b,c;
        cin >> a>>b >> c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }
    for(int i = 0 ; i < v;i++ ) {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    
    for(int i = 0; i < v;i++) {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}
