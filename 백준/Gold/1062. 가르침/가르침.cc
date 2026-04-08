#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<int> words;
int answer = 0;

void dfs(int idx, int cnt, int learned) {
    if (cnt == k) {
        int readable = 0;
        for (int word : words) {
            if ((word & learned) == word) readable++;
        }
        answer = max(answer, readable);
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (learned & (1 << i)) continue;
        dfs(i + 1, cnt + 1, learned | (1 << i));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    if (k < 5) {
        cout << 0;
        return 0;
    }

    if (k == 26) {
        cout << n;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int mask = 0;
        for (int j = 4; j < (int)s.size() - 4; j++) {
            mask |= (1 << (s[j] - 'a'));
        }
        words.push_back(mask);
    }

    int learned = 0;
    learned |= (1 << ('a' - 'a'));
    learned |= (1 << ('n' - 'a'));
    learned |= (1 << ('t' - 'a'));
    learned |= (1 << ('i' - 'a'));
    learned |= (1 << ('c' - 'a'));

    dfs(0, 5, learned);

    cout << answer;
    return 0;
}