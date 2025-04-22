#include<iostream>
#include<string>
using namespace std;

int N, K;

int make_num() {
	int answer = 0;
	int idx = 0;
	int s = 1;
	while (s <= N) {
		string str = to_string(s);
		idx += str.size();
		if (idx >= K) {
			int tmp = idx - str.size();

			answer = str[K - tmp - 1] - '0';

			return answer;
		}
		s++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> K;

	cout << make_num();
}