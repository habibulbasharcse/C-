/*
       Problem Statement

You will be given a 2D matrix of size  which will contain only dot() and minus() where dot() means you can go in that cell and minus() means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of two cells - (,) and (,). You need to tell if these  and  cells are in the same component or not. Same component means you can go from  to .

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Next line will contain  and .
Last line will contain  and .
Constraints

Output Format

Output "YES" if those cell are in the same component, "NO" otherwise.
Sample Input 0

5 4
..-.
---.
..-.
--..
....
0 1
3 2
Sample Output 0

NO
Sample Input 1

5 4
....
---.
..-.
--..
....
0 1
3 2
Sample Output 1

YES

*/

#include <bits/stdc++.h>
using namespace std;

int v,e;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> mv = {{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j) {
    return (i >= 0 && i < v && j >= 0 && j < e);
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    for(int i = 0; i < 4;i++) {
        int ci = si+mv[i].first;
        int cj = sj+mv[i].second;
        
        if(isValid(ci,cj) &&!vis[ci][cj] &&  grid[ci][cj] == '.') {
            dfs(ci,cj);
        }
    }
}

int main()
{
  
    cin >> v >> e;
    
    for(int i = 0; i < v;i++) {
        for(int j = 0; j < e;j++) {
            
            cin >> grid[i][j];
        }
    }
    
    memset(vis,false,sizeof(vis));
    int si,di,sj,dj;
    cin >> si >> di >> sj >> dj;
    
    dfs(si,di);
    
    if(vis[sj][dj]) {
        cout << "YES";
    }else {
        cout <<"NO";
    }

    return 0;
}
