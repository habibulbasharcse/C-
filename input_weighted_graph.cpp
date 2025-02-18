// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int v,e;
    cin >> v >> e;
    vector<pair<int,int>>adjList[v];
    while(e--) {
        int a,b,c;
        cin >> a>>b >> c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }
    for(int i = 0 ; i < v;i++ ) {
        cout << i << " -> ";
        for(pair<int,int> p : adjList[i] ) {
            cout << p.first << " " << p.second << ",";
        }
        cout << endl;
    }
    return 0;
}
