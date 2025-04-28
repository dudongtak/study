#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int S;
vector<vector<bool>> visit(2001, vector<bool>(2001, false));
typedef struct info {
	int clip;
	int num;
	int cnt;
}info;

int bfs() {
	info i;
	i.clip = 0;
	i.cnt = 0;
	i.num = 1;
	visit[i.num][i.clip] = true;

	queue<info> q;
	q.push(i);

	while (!q.empty()) {
		int clip = q.front().clip;
		int num = q.front().num;
		int cnt = q.front().cnt;

		if (num == S)return cnt;
		q.pop();

		if (!visit[num][num]) {
			visit[num][num] = true;
			q.push({ num,num,cnt + 1 });
		}

		if (clip > 0 && num + clip <= 2000 && !visit[num + clip][clip]) {
			visit[num + clip][clip] = true;
			q.push({ clip,num + clip,cnt + 1 });
		}

		if (num > 0 && !visit[num - 1][clip]) {
			visit[num - 1][clip] = true;
			q.push({ clip,num - 1,cnt + 1 });
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	cout << bfs();
}