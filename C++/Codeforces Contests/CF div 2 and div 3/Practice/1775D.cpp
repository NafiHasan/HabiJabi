#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 300005;
vector<bool>prime(N + 1, 1);
vector<int> primes;

void sieve() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (!prime[i])continue;
		for (int j = i * i ; j <= N; j += i)prime[j] = 0;
	}
	for (int i = 2; i < N; i++) {
		if (prime[i])primes.push_back(i);
	}

}

vector<int> edge[2 * N + 10], path;
vector<int> par(2 * N + 10, -1), dist(2 * N + 10 , INT_MAX);
void factorize(int n, int index) {
	int ind = 0;
	int tmp = n;
	while (ind < primes.size() && primes[ind] * primes[ind] <= n) {
		bool don = 0;
		while (tmp % primes[ind] == 0) {
			don = 1;
			tmp /= primes[ind];
		}
		if (don) {
			// cout << n << ' ' << tmp << ' ' << primes[ind] << ' ' << index << '\n';
			edge[index].push_back(primes[ind]);
			edge[primes[ind]].push_back(index);
		}
		ind++;
	}
	if (tmp > 1) {
		edge[tmp].push_back(index);
		edge[index].push_back(tmp);
	}
}

void bfs(int s, int t) {
	dist[s] = 0;
	queue<int> q;
	vector<bool> vis(2 * N + 10, 0);
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 1;
		for (int v : edge[u]) {
			// if (u <= 15)cout << u << ' ' << v << '\n';
			// else cout << u - 15 << ' ' << v << '\n';
			if (!vis[v] && dist[v] > (dist[u] + 1)) {
				dist[v] = dist[u] + 1;
				par[v] = u;
				q.push(v);
			}
		}
	}
	if (dist[t] == INT_MAX) {
		path.push_back(-1);
		return ;
	}
	int ss = s, tt = t;
	while (tt != ss) {
		path.push_back(tt);
		tt = par[tt];
	}

	path.push_back(ss);
	reverse(path.begin(), path.end());
}


int main() {
	FastIO;
	sieve();
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		// factorize(a[i], n + i + 1);
	}
	for (int i = 0; i < n; i++) {
		factorize(a[i], mx + i + 1);
	}
	int s, t;
	cin >> s >> t;
	int ans = 0;
	bfs(s + mx, t + mx);
	if (path[0] == -1) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < path.size(); i++) {
		if (path[i] > mx)ans++;
	}
	cout << ans << '\n';
	for (int i = 0; i < path.size(); i++) {
		if (path[i] > mx)cout << path[i] - mx << ' ';
	}
	cout << '\n';
	return 0;
}