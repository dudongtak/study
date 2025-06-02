#include<iostream>
#include<vector>
using namespace std;

int N;
vector<bool> winner(1001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	winner[1] = false;
	winner[2] = true;
	winner[3] = false;
	winner[4] = true;

	for (int i = 5; i <= 1000; i++) {
		if (!winner[i - 1] || !winner[i - 3] || !winner[i - 4])winner[i] = true;
		else winner[i] = false;
	}

	if (winner[N])cout << "SK";
	else cout << "CY";
}