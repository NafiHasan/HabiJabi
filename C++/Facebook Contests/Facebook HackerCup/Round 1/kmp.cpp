#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 1000005;
string s, p;
int n, m;
vector<int> b(N, 0);
int cnt = 0;

void kmpProcess() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j])j = b[j];
		i++; j++;
		b[i] = j;
	}
}

vector<int> kmpSearch() {
	vector<int> ind;
	cnt = 0;
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && s[i] != p[j])j = b[j];
		i++, j++;
		if (j == m) {
			ind.push_back(i - j);
			j = b[j];
		}
	}
	return ind;
}


int main() {
	FastIO;
	s = "aaaabaabaababaabaabaabaa";
	n = s.size();
	p = "aabaabaab";
	m = p.size();
	kmpProcess();
	vector<int>ans = kmpSearch();
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
	return 0;
}