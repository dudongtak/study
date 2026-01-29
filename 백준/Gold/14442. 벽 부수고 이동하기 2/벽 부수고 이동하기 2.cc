#include <bits/stdc++.h>
using namespace std;

struct Coord {
    int x, y, crash;
};

int n, m, k;
vector<string> board;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    board.resize(n);
    for (int i = 0; i < n; i++) cin >> board[i];

    vector<vector<vector<bool>>> visited(
        n, vector<vector<bool>>(m, vector<bool>(k + 1, false))
    );

    queue<Coord> q;
    visited[0][0][0] = true;
    q.push({0, 0, 0});

    int dist = 1;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y, c] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) {
                cout << dist;
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if (board[nx][ny] == '1') {
                    if (c < k && !visited[nx][ny][c + 1]) {
                        visited[nx][ny][c + 1] = true;
                        q.push({nx, ny, c + 1});
                    }
                } else {
                    if (!visited[nx][ny][c]) {
                        visited[nx][ny][c] = true;
                        q.push({nx, ny, c});
                    }
                }
            }
        }
        dist++;
    }

    cout << -1;
    return 0;
}
