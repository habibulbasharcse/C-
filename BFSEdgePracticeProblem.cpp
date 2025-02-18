/*
Question: You will be given an undirected graph as input. Then you will be given a node N. You need to print the number of nodes that are directly connected to the node N.

Sample Input 1
6 5
0 1
0 2
0 3
2 3
4 5
2

Sample Output 1

2

Sample Input 2

6 5
0 1
0 2
0 3
2 3
4 5
0

Sample Output 2

3

Sample Input 3

7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6
1

Sample Output 3

3



*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int vertex,edge;
    cin >> vertex >> edge;
    vector<pair<int,int>> adj_edge;
    while(edge--) {
        int a,b;
        cin>> a >> b;
        adj_edge.push_back({a,b});
    }
   int count = 0;
   int node;
   cin >> node;
   
   for(auto x : adj_edge) {
       if(x.first == node ) {
           count+= 1;
       }
       if(x.second == node ) {
           count+= 1;
       }
   }
   
   cout << count;
    
    return 0;
}
