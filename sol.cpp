#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
	if (a == 0) {
		return b;
	}
	return GCD(b % a, a);
}

void TestCase() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	if (n < m) { // assume s >= t (in terms of length)
		swap(s, t);
	}
	n = s.size();
	m = t.size();
	// n * k = GCD(n, k) * LCM(n, k)
	// LCM(n, k) = (n * k) / GCD(n, k)
	int lcm = (n * m) / GCD(n, m);
	string a = "";
	for (int i = 0; i < lcm; i++) { // form the string LCM using string s
		a += s[i%n];
	}
	string b = "";
	for (int i = 0; i < lcm; i++) { // form the string LCM using string t
		b += t[i%m];
	}
	// check if formed two strings are equal to each other
	cout << (a == b ? a : "-1") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		TestCase();
	}
	return 0;
}

