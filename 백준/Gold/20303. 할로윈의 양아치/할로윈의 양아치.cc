#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, k;
vector<int> parent, groupSize, candySum, candy;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    parent[b] = a;
    groupSize[a] += groupSize[b];
    candySum[a] += candySum[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    candy.resize(n);
    parent.resize(n);
    groupSize.assign(n, 1);
    candySum.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> candy[i];
        parent[i] = i;
        candySum[i] = candy[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a-1, b-1);
    }

    vector<pair<int, int>> groups;
    for (int i = 0; i < n; i++) {
        if (Find(i) == i) {
            groups.push_back({groupSize[i], candySum[i]});
        }
    }

    vector<int> dp(k, 0);

    for (auto [cnt, sum] : groups) {
        for (int j = k - 1; j >= cnt; j--) {
            dp[j] = max(dp[j], dp[j - cnt] + sum);
        }
    }

    cout << dp[k - 1];
}