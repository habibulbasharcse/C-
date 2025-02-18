/*Problem Statement

You will be given a 2D matrix of size  which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Constraints

Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1
*/

#include <bits/stdc++.h>
using namespace std;

int v,e;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> mv = {{0,1},{0,-1},{1,0},{-1,0}};

int area;
bool isValid(int i,int j) {
    return (i >= 0 && i < v && j >= 0 && j < e);
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    area++;
    for(int i = 0; i < 4;i++) {
        int ci = si+mv[i].first;
        int cj = sj+mv[i].second;
        
        if(isValid(ci,cj) &&!vis[ci][cj] && grid[ci][cj] == '.') {
            
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
    int maxArea = INT_MAX;
    bool flag = false;
    for(int i = 0; i < v;i++) {
        for(int j = 0; j < e;j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                area = 0;
                dfs(i, j);
                flag = true;
                maxArea = min(maxArea,area);
            }
        }
    }
    if(flag) {
        cout << maxArea;
    }else {
        cout <<"-1";
    }
    
    return 0;
