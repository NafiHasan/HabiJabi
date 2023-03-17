#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 1000005;
string s, p;
int n, m;
vector<int> b(N, 0);

void prefun() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j])j = b[j];
		i++; j++;
		b[i] = j;
	}
}



int main() {
	FastIO;
	p = "aabaabaab";
	m = p.size();
	prefun();
	for (int i = 0; i <= m; i++)cout << b[i] << ' ';
	return 0;
}