//http://hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/knight-moves-2
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> knightMoves = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
    {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};


bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int minKnightMoves(int n, int m, int kx, int ky, int qx, int qy) {
    if (kx == qx && ky == qy) return 0;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    q.push({kx, ky});
    visited[kx][ky] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        steps++;

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : knightMoves) {
                int nx = x + dx, ny = y + dy;

                if (isValid(nx, ny, n, m) && !visited[nx][ny]) {
                    if (nx == qx && ny == qy) return steps;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n, m, kx, ky, qx, qy;
        cin >> n >> m;  
        cin >> kx >> ky;   
        cin >> qx >> qy;
        
        cout << minKnightMoves(n, m, kx, ky, qx, qy) << endl;
    }

    return 0;
}

