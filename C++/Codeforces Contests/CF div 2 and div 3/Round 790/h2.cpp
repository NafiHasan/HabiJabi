#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		indexed_multiset s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long cnt = s.order_of_key(a[i] + 1);
			ans += cnt - 1;
			indexed_multiset :: iterator it = s.upper_bound(a[i]);
			if (it != s.end())s.erase(it);
		}
		cout << ans << '\n';
	}
	return 0;
}