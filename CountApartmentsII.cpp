/*
  Problem Statement

You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number rooms in each of the apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

You need to print the count of the rooms in ascending order. If there are no apartments available in that building, then you should print .

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).
Constraints

Output Format

Output the number of rooms in each of the apartments in ascending order.
Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 0

2 2 8
Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#
Sample Output 1

1 1 2 8 10
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

int dfs(int si, int sj) {
    if (vis[si][sj]) return 0;
    vis[si][sj] = true;
    int room_count = 1;
    
    for (auto move : mv) {
        int ci = si + move.first;
        int cj = sj + move.second;
        
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
            room_count += dfs(ci, cj);
        }
    }
    return room_count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<int> apartment_sizes;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                apartment_sizes.push_back(dfs(i, j));
            }
        }
    }

    if (!apartment_sizes.empty()) {
        sort(apartment_sizes.begin(), apartment_sizes.end());
        for (int size : apartment_sizes) {
            cout << size << " ";
        }
        cout << endl;
    }else {
        cout << "0"<< endl;
    }
    
    return 0;
}
