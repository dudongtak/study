#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

char board[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
set<set<pair<int,int>>> answer;

bool is_connected(const vector<pair<int,int>>& pos) {
    queue<pair<int,int>> q;
    set<pair<int,int>> visited;
    q.push(pos[0]);
    visited.insert(pos[0]);

    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx<0 || ny<0 || nx>=5 || ny>=5) continue;
            if(find(pos.begin(), pos.end(), make_pair(nx, ny)) != pos.end()
               && visited.find({nx, ny}) == visited.end()) {
                visited.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    return visited.size() == 7;
}

void comb(int start, vector<pair<int,int>> selected) {
    if(selected.size() == 7) {
        int cntS = 0;
        for(auto s : selected) {
            int x=s.first;
            int y=s.second;
            if(board[x][y] == 'S') cntS++;
        }
        if(cntS >= 4 && is_connected(selected)) {
            set<pair<int,int>> temp(selected.begin(), selected.end());
            answer.insert(temp);
        }
        return;
    }

    for(int i=start; i<25; i++) {
        int x = i / 5;
        int y = i % 5;
        selected.push_back({x, y});
        comb(i+1, selected);
        selected.pop_back();
    }
}

int main() {
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> board[i][j];

    comb(0, {});
    cout << answer.size();
}
