/*
    Problem Statement

You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number of apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).
Constraints

Output Format

Output the number of apartments
Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 0

3
Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#
Sample Output 1

5
*/


#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005]; 
bool vis[1005][1005]; 
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m; 

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}


void dfs(int si, int sj) {
    if (vis[si][sj]) return; 
    
    vis[si][sj] = true;
    
    for (int i = 0; i < 4; i++) {
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;
        
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    memset(vis, false, sizeof(vis)); 

    int apartment_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j); 
                apartment_count++; 
            }
        }
    }

    cout << apartment_count << endl;  
    return 0;
}

