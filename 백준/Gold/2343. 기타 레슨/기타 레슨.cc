#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> study;

bool check(int size) {
    int count = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + study[i] > size) {
            count++;
            sum = study[i];
        } else {
            sum += study[i];
        }
    }
    return count <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    study.resize(n);

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        cin >> study[i];
        left = max(left, study[i]);
        right += study[i];
    }

    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer;
}