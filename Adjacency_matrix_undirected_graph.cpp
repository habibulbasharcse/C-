#include <bits/stdc++.h>
using namespace std;

int main() {
    int node, edge;
    cin >>node >> edge;
    int mat[node][node];
    /*for(int i = 0;i < node ;i++) {
        for(int j = 0; j < edge;j++) {
            mat[i][j] = 0;
           
        }
    }*/
    
    memset(mat,0,sizeof(mat)); //shortcut of set value of 2d array
    for(int i = 0;i < node ;i++) {
        for(int j = 0; j < edge;j++) {
            if(i == j) {
                mat[i][j] = 1;
            }
           
        }
    }
    
    for(int i = 0; i < edge;i++) {
        int a,b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for(int i = 0;i < node ;i++) {
        for(int j = 0; j < edge;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
