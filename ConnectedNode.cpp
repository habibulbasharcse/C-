/*
  Problem Statement

You will be given an undirected graph as input. Then you will be given  queries. For each query you will be given a node . You need to print the nodes that are connected with  in descending order.

Note: If there is no node connected to , then print -1.

Input Format

The first line will contain  and , the number of nodes and the number of edges, respectively. The values of the nodes range from  to .
Next  lines will contain two node values which means there is a connection between first node and second node.
The next line will contain .
The following  lines will each contain .
Constraints

Output Format

Output the nodes that are connected with  in descending order.
Sample Input 0

6 8
0 4
0 5
4 2
4 3
5 3
2 0
0 1
1 3
6
0
1
2
3
4
5
Sample Output 0

5 4 2 1 
3 0 
4 0 
5 4 1 
3 2 0 
3 0 
Sample Input 1

5 3
0 1
1 2
0 4
2
3
0
Sample Output 1

-1
4 1 
*/

#include <bits/stdc++.h>

using namespace std;



int main()
{
    int v,e;
    cin >> v >> e;
    vector<int>adjList[v];
    
    while(e--) {
        int a,b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    
    
    int q;
    cin >> q;
    
    while(q--) {
        int a;
        cin >> a;
        vector<int>arr;
        for(int adj : adjList[a] ) {
            arr.push_back(adj);
        }
        if(arr.empty()) {
            cout << "-1" << endl;
        }else {
            sort(arr.begin(), arr.end(), greater<int>());
            for(int x : arr) {
                cout << x << " " ;
            }
            cout << endl;
        }
    }
    
    
    

    return 0;
}

