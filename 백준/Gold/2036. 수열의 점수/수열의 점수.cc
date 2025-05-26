#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;
priority_queue<ll> pos;
priority_queue <ll, vector<ll>, greater< >> neg;
int N;
ll num;
ll answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num <= 0)neg.push(num);
		else pos.push(num);
	}

	while (pos.size() > 1) {
		ll num1 = pos.top();
		pos.pop();
		ll num2 = pos.top();
		pos.pop();

		if (num1*num2 > num1 + num2)answer += num1 * num2;
		else answer += num1 + num2;
	}
	while (neg.size() > 1) {
		ll num1 = neg.top();
		neg.pop();
		ll num2 = neg.top();
		neg.pop();

		answer += num1 * num2;
	}
	
	if (!pos.empty())answer += pos.top();
	if (!neg.empty())answer += neg.top();

	cout << answer;
}