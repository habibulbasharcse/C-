//https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/maze-19

#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
pair<int, int> parent[105][105];

int n, m;
vector<pair<int, int>> mv = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !vis[i][j]);
}

void bfs(int si, int sj) {
    
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {-1, -1};

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        if (grid[par_i][par_j] == 'D') return;

        for (int i = 0; i < 4; i++) {
            
            int ci = par_i + mv[i].first;
            int cj = par_j + mv[i].second;
            
            if (valid(ci, cj)) {
                
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}

void mark_path(int si, int sj, int di, int dj) {
    while (di != si || dj != sj) {
        int px = parent[di][dj].first;
        int py = parent[di][dj].second;
        
        if (grid[px][py] != 'R') grid[px][py] = 'X';
        di = px, dj = py;
    }
}

int main() {
    cin >> n >> m;
    int si, sj;
    int di = -1;
    int dj = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                si = i;
                sj = j;
            }    
            if (grid[i][j] == 'D'){ 
                di = i;
                dj = j;
            }    
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(si, sj);

    if (vis[di][dj])
        mark_path(si, sj, di, dj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}

