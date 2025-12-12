#include <iostream>
#include <vector>
using namespace std;

int n;
struct food {
    int p, f, c, v, cost;
};

food s;
vector<food> foods;
vector<int> ans;
int Min = 100000000;

bool check(food &sum) {
    if (sum.p < s.p) return false;
    if (sum.f < s.f) return false;
    if (sum.c < s.c) return false;
    if (sum.v < s.v) return false;
    return true;
}

void dfs(int idx, food &sum, vector<int> &v) {
    if (sum.cost > Min) return;

    if (idx == n) {
        if (check(sum)) {
            if (sum.cost < Min) {
                Min = sum.cost;
                ans = v;
            }
            else if (sum.cost == Min && v < ans) {
                ans = v;
            }
        }
        return;
    }

    v.push_back(idx + 1);
    sum.p += foods[idx].p;
    sum.f += foods[idx].f;
    sum.c += foods[idx].c;
    sum.v += foods[idx].v;
    sum.cost += foods[idx].cost;
    dfs(idx + 1, sum, v);
    v.pop_back();
    sum.p -= foods[idx].p;
    sum.f -= foods[idx].f;
    sum.c -= foods[idx].c;
    sum.v -= foods[idx].v;
    sum.cost -= foods[idx].cost;

    dfs(idx + 1, sum, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    foods.resize(n);

    cin >> s.p >> s.f >> s.c >> s.v;
    for (int i = 0; i < n; i++) {
        cin >> foods[i].p >> foods[i].f
            >> foods[i].c >> foods[i].v
            >> foods[i].cost;
    }

    vector<int> v;
    food sum = {0, 0, 0, 0, 0};

    dfs(0, sum, v);

    if (Min == 100000000) {
        cout << -1;
        return 0;
    }

    cout << Min << "\n";
    for (int x : ans) cout << x << " ";
}
