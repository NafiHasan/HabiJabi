#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pair_set;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<int> col(n), num(n);
	ordered_pair_set cl;
	ordered_set st;
	for (int i = 0; i < n; i++) {
		cin >> col[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		cl.insert({col[i], num[i]});
		st.insert(num[i]);
	}
	long long ans = 0;
	for (int i = n - 1; i > 0; i--) {
		long long cnt = st.size() - st.order_of_key(num[i] + 1);// to find the number of values greater than current number(num[i])

		cnt -= cl.order_of_key({col[i] + 1 , 0}) - cl.order_of_key({col[i], num[i] + 1}); //subtracting those pairs, which have the same color as current number and number greater than current one.
		ans += cnt;
		st.erase(st.find_by_order(st.order_of_key(num[i])));
		cl.erase(cl.find_by_order(cl.order_of_key({col[i], num[i]})));
	}
	cout << ans << '\n';
	return 0;
}