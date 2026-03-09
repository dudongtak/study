#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };

int m, n;

typedef struct mood {
	int x, y;
}mood;

vector<vector<int>> map(500, vector<int>(500, -1));
vector<vector<int>> noc(500, vector<int>(500, -1));


int dfs(int X,int Y) {
	if (X == m - 1 && Y == n - 1) {
		return 1;
	}
	if (noc[X][Y] != -1)return noc[X][Y];

	noc[X][Y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = X + x[i];
		int yy = Y + y[i];
		if (xx >= 0 && yy >= 0 && xx < m&&yy < n) {
			if (map[xx][yy] < map[X][Y]) {
				noc[X][Y] = noc[X][Y] + dfs(xx, yy);
			}
		}
	}
	return noc[X][Y];
}

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			map[i][j] = num;
		}
	}

	int answer = dfs(0, 0);

	printf("%d", answer);
}