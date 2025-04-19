#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

int N, num;
vector<int> city;
vector<vector<int>> edge;
vector<vector<int>> comb;
int Min = 1000000000;
int sA = 0, sB = 0;

int bfs(vector<bool> section,bool s,int start) {
	int cnt = 1;
	queue<int> q;
	vector<bool> visit(N + 1, false);

	q.push(start);
	visit[start] = true;
	if (s) {
		sA += city[start];
	}
	else {
		sB += city[start];
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (!visit[next] && section[next] == s) {
				q.push(next);
				cnt++;
				visit[next] = true;
				if (s) {
					sA += city[next];
				}
				else {
					sB += city[next];
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	city.resize(N + 1);
	edge.resize(N + 1);

	for (int i = 1; i <= N; i++)cin >> city[i];

	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			int next; cin >> next;
			edge[i].push_back(next);
		}
	}
	vector<bool> loc(N);

	for (int i = 1; i <= N / 2; i++) {
		loc[i - 1] = true;
		do {
			vector<bool> section(N + 1, false);
			for (int i = 0; i < N; i++) {
				if (loc[i])section[i+1]=true;
			}
			
			int idxA = 0, idxB = 0;
			for (int i = 1; i <= N; i++) {
				if (idxA != 0 && idxB != 0)break;
				if (section[i])idxA = i;
				if (!section[i])idxB = i;
			}

			int sum = bfs(section, true, idxA) + bfs(section, false, idxB);

			if (sum == N)Min = min(Min, abs(sA - sB));
			sA = 0; sB = 0;
		} while (prev_permutation(loc.begin(), loc.end()));
	}
	

	if (Min == 1000000000)cout << -1;
	else cout << Min;
}