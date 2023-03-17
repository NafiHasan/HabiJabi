#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 5000005;
string s, p;
int nn, mm;
vector<int> b(N, 0);
int cnt = 0;

void kmpProcess() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < mm) {
		while (j >= 0 && p[i] != p[j])j = b[j];
		i++; j++;
		b[i] = j;
	}
}

bool kmpSearch() {
	vector<int> ind;
	cnt = 0;
	int i = 0, j = 0;
	while (i < nn) {
		while (j >= 0 && s[i] != p[j])j = b[j];
		i++, j++;
		if (j == mm) {
			return 1;
		}
	}
	return 0;
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		int n, k;
		cin >> n >> k;
		s = ""; p = "";

		bool all = 1;
		vector<int> a(n), b(n), part1, part2;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i && a[i] != a[i - 1])all = 0;
			s += to_string(a[i]) + "#";
		}
		s += s;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			p += to_string(b[i]) + "#";
		}
		nn = s.size(); mm = p.size();
		kmpProcess();
		bool same = 0;
		if (a == b)same = 1;

		if (!same && k == 0) {
			cout << "NO\n";
			continue;
		}
		if (same && k == 1 && !all) {
			cout << "NO\n";
			continue;
		}
		if (same && n == 2 && (k % 2 == 1) && !all) {
			cout << "NO\n";
			continue;
		}
		if (!same && n == 2 && (k % 2 == 0) && !all) {
			cout << "NO\n";
			continue;
		}
		if (same && k > 1) {
			cout << "YES\n";
			continue;
		}
		bool ok = kmpSearch();

		if (ok)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}