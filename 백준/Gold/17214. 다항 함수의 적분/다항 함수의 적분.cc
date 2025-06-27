#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	string poly;
	cin >> poly;
	int coef1 = 0;
	int coef2 = 0;
	if (poly.find('x') != string::npos) {
		string str1 = "";
		int index = 0;
		while (poly[index] != 'x') {
			str1 += poly[index];
			index++;
		}
		coef1 = stoi(str1);
		if (poly.size() != poly.find('x') + 1) {
			coef2 = stoi(poly.substr(poly.find('x') + 1));
		}
		else {
			coef2 = 0;
		}
	}
	else {
		coef1 = 0;
		coef2 = stoi(poly);
	}

	string s2 = "";
	if (coef2 > 0 && coef1 != 0) {
		s2 = "+";
	}
	s2 += to_string(coef2);
	if (coef1 != 0 && coef2 == 1) {
		s2 = "+";
	}
	else if (coef1 != 0 && coef2 == -1) {
		s2 = "-";
	}
	else if (coef1 == 0 && coef2 == 1) {
		s2 = "";
	}
	else if (coef1 == 0 && coef2 == -1) {
		s2 = "-";
	}

	if (coef1 != 0 && coef1 != 2 && coef1 != -2 && coef2 != 0) {
		cout << coef1 / 2 << "xx" << s2 << "x+W" << '\n';
	}
	else if (coef1 != 0 && coef1 != 2 && coef1 != -2 && coef2 == 0) {
		cout << coef1 / 2 << "xx+W" << '\n';
	}
	else if (coef1 == 0 && coef2 != 0) {
		cout << s2 << "x+W" << '\n';
	}
	else if (coef1 == 0 && coef2 == 0) {
		cout << "W" << '\n';
	}
	else if (coef1 == 2 && coef2 != 0) {
		cout << "xx" << s2 << "x+W" << '\n';
	}
	else if (coef1 == 2 && coef2 == 0) {
		cout << "xx+W" << '\n';
	}
	else if (coef1 == -2 && coef2 == 0) {
		cout << "-xx+W" << '\n';
	}
	else if (coef1 == -2 && coef2 != 0) {
		cout << "-xx" << s2 << "x+W" << '\n';
	}

}