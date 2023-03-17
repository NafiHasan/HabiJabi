#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 2e5 + 10;

vector<int> par(N), rnk(N, 0);
vector<int> ans(N, -1);

void makeset() {
	for (int i = 0; i < N; i++)par[i] = i;
}

int get(int a) {
	return (par[a] == a ? a : get(par[a]));
}

int give(int a, int val) {
	if (ans[a] == -1 && a != 1)ans[a] = val;
	return (par[a] == a ? a : give(par[a], val));
}
int got = -1;
int check(int a) {
	if (ans[a] != -1)return got = ans[a];
	return (par[a] == a ? a : check(par[a]));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (a == 1)par[b] = a;
	else if (b == 1)par[a] = b;
	else if (rnk[a] > rnk[b])par[b] = a;
	else par[a] = b;
}

int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> init(n), dum(n, { -1, -1}), sched(m);
	for (int i = 0; i < n; i++)
		cin >> init[i].first >> init[i].second;
	dum = init;
	for (int i = 0; i < m; i++) {
		cin >> sched[i].first >> sched[i].second;
		if (sched[i].second == 1)
			dum[sched[i].first - 1].first = -1;
		else
			dum[sched[i].first - 1].second = -1;
	}
	makeset();

	// keeping a dummy state after applying the given chrono operations to check the final position of all monkeys
	for (int i = 0; i < n; i++) {
		if (dum[i].first != -1)
			union_set(i + 1, dum[i].first);
		if (dum[i].second != -1)
			union_set(i + 1, dum[i].second);
	}

	// going reverse chrono order to check the moment when the monkeys got attached to the root/1
	for (int i = m - 1; i >= 0; i--) {
		int mon = sched[i].first - 1, hand = sched[i].second;
		int v = init[mon].first;
		if (hand == 2) v = init[mon].second;
		int par1 = get(mon + 1), par2 = get(v);

		if (par1 == 1 && par2 != 1)
			give(v, i);
		else if (par1 != 1 && par2 == 1)
			give(mon + 1, i);
		union_set(mon + 1, v);
	}

	//checking if a parent has fallen at some moment and updating the moment for all the children
	for (int i = 2; i <= n ; i++) {
		if (ans[i] == -1) {
			got = -1;
			int no = check(i);
			if (got != -1) {
				give(i, got);
			}
		}
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << '\n';
	return 0;
}