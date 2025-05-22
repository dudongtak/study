#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> nums;
vector<long long> num;

void make_num(string n,int size,int c) {
	if (c == size) {
		num.push_back(stoll(n));
		return;
	}

	for (int i = 0; i < 10; i++) {
		char j = i + '0';
		if (j < n[n.length() - 1]) {
			make_num(n + j, size, c + 1);
		}
	}
}

int main() {
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		nums.push_back(to_string(i));
		num.push_back(i);
	}

	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			make_num(nums[j], i, 0);
		}
	}
	
	sort(num.begin(), num.end());
	int n;
	scanf("%d", &n);
	
	if (n < num.size()) {
		printf("%lld", num[n]);
	}
	else {
		printf("%d", -1);
	}
}