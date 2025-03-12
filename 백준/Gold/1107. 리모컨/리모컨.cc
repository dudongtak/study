#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

string num;
int n;
map<char, int> bd;
vector<bool> channels(1000001, true);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	cin >> n;

	for (int i = 0; i < n; i++) {
		char bd_num;
		cin >> bd_num;
		bd[bd_num]++;
	}

	if (num == "100") {
		cout << 0;
		return 0;
	}

	int Num = stoi(num);

	for (int i = 0; i < 1000001; i++) {
		string tmp = to_string(i);
		for (int j = 0; j < tmp.size(); j++) {
			if (bd[tmp[j]] == 1) {
				channels[i] = false;
				break;
			}
		}
	}

	channels[100] = true;

	int near1 = 100000001, near2 = 100000001;

	for (int i = Num; i >= 0; i--) {
		if (channels[i]) {
			near1 = i;
			break;
		}
	}

	for (int i = Num; i < abs(Num * 2 - 99); i++) {
		if (channels[i]) {
			near2 = i;
			break;
		}
	}

	near1 = abs(near1 - Num) + to_string(near1).size();
	near2 = abs(near2 - Num) + to_string(near2).size();
	cout << min(abs(Num - 100), min(near1, near2));
}