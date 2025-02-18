#include <bits/stdc++.h>
using namespace std;

int main() {
    int node,edge;
    cin >> node >> edge;
    vector< pair<int,int>> edge_list;
    while(edge--) {
        int a,b;
        cin >> a >> b;
        edge_list.push_back({a,b});
        
    }
    
    for(pair<int,int> x : edge_list) {
        cout << x.first << " " << x.second << endl;
        
    }

    return 0;
}
