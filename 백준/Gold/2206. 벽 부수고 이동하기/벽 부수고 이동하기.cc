#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

vector<vector<char>> map(1002, vector<char>(1002,'3'));
vector<vector<vector<int>>> dis(1002, vector<vector<int>>(1002, vector<int>(2, -1)));
queue<pair<pair<int, int>,int>> q;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };


int main() {
	string str;
	int n, m;
	int cnt = 0;
	int c;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			map[i][j] = str[j - 1];
		}
	}//map 생성
	dis[1][1][0] = 1;
	q.push(make_pair(make_pair(1, 1), 0));
	while (!q.empty()) {
		int X = q.front().first.first;
		int Y = q.front().first.second;
		int check = q.front().second;
		q.pop();
		if (X == n && Y == m) {
			c = check;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x[i] + X;
			int yy = y[i] + Y;
			if (dis[xx][yy][check] == -1) {
				if (map[xx][yy] == '0') {
					dis[xx][yy][check] = dis[X][Y][check] + 1;
					q.push(make_pair(make_pair(xx, yy), check));
				}
				else if (map[xx][yy] == '1'&&check==0) {
					dis[xx][yy][check + 1] = dis[X][Y][check] + 1;
					q.push(make_pair(make_pair(xx, yy), check+1));
				}
			}
		}
	}
	printf("%d", dis[n][m][c]);
}