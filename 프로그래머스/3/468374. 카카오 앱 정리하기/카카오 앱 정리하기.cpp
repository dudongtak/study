#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
vector<vector<int>> curBoard;

int dr[] = {0, 0, 1, 0, -1};
int dc[] = {0, 1, 0, -1, 0};

struct Cell {
    int r, c, id;
};

set<int> getGroup(int startApp, int dir) {
    set<int> group;
    queue<int> q;

    group.insert(startApp);
    q.push(startApp);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (curBoard[r][c] != cur) continue;

                int nr = (r + dr[dir] + N) % N;
                int nc = (c + dc[dir] + M) % M;
                int nxt = curBoard[nr][nc];

                if (nxt != 0 && !group.count(nxt)) {
                    group.insert(nxt);
                    q.push(nxt);
                }
            }
        }
    }

    return group;
}

void moveGroup(const set<int>& group, int dir) {
    vector<Cell> cells;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (group.count(curBoard[r][c])) {
                cells.push_back({r, c, curBoard[r][c]});
            }
        }
    }

    for (const auto& cell : cells) {
        curBoard[cell.r][cell.c] = 0;
    }

    for (const auto& cell : cells) {
        int nr = (cell.r + dr[dir] + N) % N;
        int nc = (cell.c + dc[dir] + M) % M;
        curBoard[nr][nc] = cell.id;
    }
}

vector<int> findBrokenApps(int dir) {
    vector<int> broken;
    bool added[101] = {false};

    if (dir == 1 || dir == 3) {
        for (int r = 0; r < N; r++) {
            int leftId = curBoard[r][0];
            int rightId = curBoard[r][M - 1];

            if (leftId == 0 || leftId != rightId) continue;

            bool brokenInThisRow = false;
            for (int c = 0; c < M; c++) {
                if (curBoard[r][c] != leftId) {
                    brokenInThisRow = true;
                    break;
                }
            }

            if (brokenInThisRow && !added[leftId]) {
                broken.push_back(leftId);
                added[leftId] = true;
            }
        }
    } else {
        for (int c = 0; c < M; c++) {
            int topId = curBoard[0][c];
            int bottomId = curBoard[N - 1][c];

            if (topId == 0 || topId != bottomId) continue;

            bool brokenInThisCol = false;
            for (int r = 0; r < N; r++) {
                if (curBoard[r][c] != topId) {
                    brokenInThisCol = true;
                    break;
                }
            }

            if (brokenInThisCol && !added[topId]) {
                broken.push_back(topId);
                added[topId] = true;
            }
        }
    }

    return broken;
}

void process(int startApp, int dir) {
    set<int> group = getGroup(startApp, dir);
    moveGroup(group, dir);

    while (true) {
        vector<int> broken = findBrokenApps(dir);
        if (broken.empty()) break;

        int brokenApp = broken[0];
        set<int> newGroup = getGroup(brokenApp, dir);
        moveGroup(newGroup, dir);
    }
}

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands) {
    N = (int)board.size();
    M = (int)board[0].size();
    curBoard = board;

    for (const auto& cmd : commands) {
        int id = cmd[0];
        int dir = cmd[1];
        process(id, dir);
    }

    return curBoard;
}