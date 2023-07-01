#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// const int N = 200005;

// long long a[N], tree[N * 4];

// void init (int node , int lo, int hi) {
// 	if (lo == hi) {
// 		tree[node] = a[lo];
// 		return;
// 	}
// 	int left = node * 2 , right = left + 1;
// 	int mid = (lo + hi) / 2 ;
// 	init (left, lo, mid);
// 	init (right, mid + 1, hi);
// 	tree[node] = max(tree[left] , tree[right]);
// }

// long long query(int node, int lo, int hi, int i, int j) {
// 	if (i > hi || j < lo) return 0;
// 	if (lo >= i && hi <= j) return tree[node];

// 	int left = node * 2 , right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	return max(query (left, lo, mid, i, j) , query (right, mid + 1, hi, i, j));
// }

// void update(int node, int lo, int hi, int i, long long new_value) {
// 	if (i < lo || i > hi) return;
// 	if (lo == hi) {
// 		tree[node] = new_value;
// 		return;
// 	}
// 	int left = node * 2, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	update(left, lo, mid, i, new_value);
// 	update(right, mid + 1, hi, i, new_value);
// 	tree[node] = tree[left] + tree[right];
// }



int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	vector<int> freq(200005, 0), a(n);
	set<int, greater<int>> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
		freq[a[i]]++;
	}
	for (int i = 1; i <= 200001; i++) {
		// int inc = log2(freq[i -1 ]);
		freq[i] += (freq[i - 1]) / 2;
		if (i < 10)cout << i << ' ' << freq[i] << '\n';
	}
	while (q--) {
		int ind, x;
		cin >> ind >> x;
		for (int i = a[ind - 1]; i < 200005 ; i++) {
			int f = log2(freq[i]);
			f = pow(2, f);
			cout << i << ' ' << freq[i] << ' ' << f << '\n' ;
			if (freq[i] > 1 && freq[i] == f) {
				freq[i]--;
				if (freq[i] == 0) {
					st.erase(st.find(i));
				}
				continue;
			}
			freq[i]--;
			break;
		}
		// update(1, 0, n-1, ind - 1, x);
		a[ind - 1] = x;
		for (int i = a[ind - 1]; i < 200005 ; i++) {
			freq[i]++;
			st.insert(i);
			int f = log2(freq[i]);
			f = pow(2, f);
			cout << i << ' ' << freq[i] << ' ' << f << '\n' ;
			if (freq[i] > 1 && freq[i] == f) {
				continue;
			}
			break;
		}
		cout << *st.begin() << '\n';
	}
	return 0;
}