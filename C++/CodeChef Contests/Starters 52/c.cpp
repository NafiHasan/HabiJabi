#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 100005;

long long a[N];
struct info {
	long long prop, sum;
} tree[N * 4];

void clear(int n) {
	for (int i = 0; i <= n; i++)a[i] = 0;
	for (int i = 0; i <= 4 * n; i++) {
		tree[i].sum = 0;
		tree[i].prop = 0;
	}
}

// void init(int node, int lo, int hi){
// 	if(lo == hi) {
// 		tree[node].sum = a[lo];
// 		return;
// 	}
// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	init(left, lo, mid);
// 	init(right, mid + 1, hi);
// 	tree[node].sum = tree[left].sum + tree[right].sum;
// }

long long query(int node, int lo, int hi, int i, int j, long long carry = 0LL) {
	if (i > hi || j < lo) return 0;
	if (i <= lo && j >= hi)return tree[node].sum + carry * (hi - lo + 1) * 1LL;

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;

	return query(left, lo, mid, i , j , carry + tree[node].prop) + query(right, mid + 1, hi, i , j , carry + tree[node].prop);
}

void update(int node, int lo, int hi, int i, int j, long long val) {
	if (i > hi || j < lo) return;
	if (i <= lo && j >= hi) {
		tree[node].sum += 1LL * (hi - lo + 1) * val;
		tree[node].prop += val;
		return;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (hi - lo + 1) * tree[node].prop * 1LL;
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		clear(n);
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			long long cnt = query(1, 0, n - 1, i, i, 0);
			// cout << cnt << ' ';
			if (s[i] == '0' && cnt % 2 == 0) {
				continue;
			} else if (s[i] == '1' && cnt % 2 == 1) {
				s[i] = '0';
				continue;
			} else {
				if (i <= (n - k)) {
					update(1, 0 , n - 1, i, i + k - 1, 1LL);
					// cout << "u " << i << '\n';
					s[i] = '0';
				} else if (s[i] == '1' && cnt % 2 == 0) {
					continue;
				} else if (s[i] == '0' && cnt % 2 == 1) {
					s[i] = '1';
				}
			}
		}
		cout << s << '\n';
	}
	return 0;
}