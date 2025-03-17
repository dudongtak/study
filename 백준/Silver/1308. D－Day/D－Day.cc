#include<iostream>
using namespace std;

bool isLeap(int y) {
	if (y % 400 == 0) {
		return true;
	}
	else if (y % 100 == 0) {
		return false;
	}
	else if (y % 4 == 0) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cur[3];
	int dday[3];
	cin >> cur[0] >> cur[1] >> cur[2] >> dday[0] >> dday[1] >> dday[2];

	if (dday[0] - cur[0] >= 1000) {
		if (dday[0] - cur[0] == 1000) {
			if (cur[1] < dday[1]) {
				cout << "gg";
				return 0;
			}
			else if (cur[1] == dday[1] && cur[2] <= dday[2]) {
				cout << "gg";
				return 0;
			}
		}
		else {
			cout << "gg";
			return 0;
		}
	}
	int answer = 0;
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (cur[0] != dday[0]) {
		for (int i = cur[0]; i <= dday[0]; i++) {
			if (i == cur[0]) {
				if (isLeap(cur[0])) {
					month[2] = 29;
				}
				answer += month[cur[1]] - cur[2];
				for (int j = cur[1] + 1; j <= 12; j++) {
					answer += month[j];
				}
				month[2] = 28;
			}
			else if (i == dday[0]) {
				if (isLeap(dday[0]))month[2] = 29;
				for (int j = 1; j < dday[1]; j++) {
					answer += month[j];
				}
				answer += dday[2];
				month[2] = 28;
			}
			else {
				if (isLeap(i)) {
					answer += 366;
				}
				else {
					answer += 365;
				}
			}
		}
	}
	else {
		if (isLeap(cur[0])) {
			month[2] = 29;
		}
		for (int i = cur[1]; i <= dday[1]; i++) {
			if (i == cur[1]) {
				answer += month[i] - cur[2];
			}
			else if (i == dday[1]) {
				answer += dday[2];
			}
			else {
				answer += month[i];
			}
		}
	}

	cout << "D-" << answer;
}