#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool sec(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second < b.second);
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m , k;
		cin >> n >> m >> k;
		vector<int> ver(n), hor(m);
		for (int i = 0; i < n; i++)cin >> ver[i];
		for (int i = 0; i < m; i++)cin >> hor[i];
		vector<pair<int, int>>poi(k);
		for (int i = 0; i < k; i++) cin >> poi[i].first >> poi[i].second;

		// checking for vertical lines
		long long ans = 0;
		sort (poi.begin(), poi.end());
		for (int i = 1; i < n; i++) {
			int l = ver[i - 1], r = ver[i];
			int lo = 0 , hi = k - 1, mid;
			long long start = -1, end = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (poi[mid].first >= r)hi = mid - 1;
				else if (poi[mid].first <= l) lo = mid + 1;
				else if (poi[mid].first > l && poi[mid].first < r) {
					hi = mid - 1;
					start = mid;
				}
			}

			lo = 0, hi = k - 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (poi[mid].first >= r)hi = mid - 1;
				else if (poi[mid].first <= l) lo = mid + 1;
				else if (poi[mid].first > l && poi[mid].first < r) {
					lo = mid + 1;
					end = mid;
				}
			}
			ans += (long long)((end - start + 1) * (end - start) / 2);

			if (start >= 0 && end >= 0) {
				map<int, int> same;
				for (int j = start ; j <= end; j++) same[poi[j].second]++;

				for (int j = start ; j <= end; j++) {
					long long has = same[poi[j].second];
					ans -= (long long)(has * (has - 1) / 2);
					same[poi[j].second] = 0;
				}
			}
		}

		// checking horizontal
		sort (poi.begin(), poi.end(), sec);
		for (int i = 1; i < m; i++) {
			int l = hor[i - 1], r = hor[i];
			int lo = 0 , hi = k - 1;
			int mid;
			long long start = -1, end = -1;

			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (poi[mid].second >= r)hi = mid - 1;
				else if (poi[mid].second <= l) lo = mid + 1;
				else if (poi[mid].second > l && poi[mid].second < r) {
					hi = mid - 1;
					start = mid;
				}
			}

			lo = 0, hi = k - 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (poi[mid].second >= r)hi = mid - 1;
				else if (poi[mid].second <= l) lo = mid + 1;
				else if (poi[mid].second > l && poi[mid].second < r) {
					lo = mid + 1;
					end = mid;
				}
			}
			ans += (end - start + 1) * (end - start) / 2LL;
			map<int, int> same;
			if (start >= 0 && end >= 0 ) {
				for (int j = start ; j <= end; j++) {
					same[poi[j].first]++;
				}
				for (int j = start ; j <= end; j++) {
					long long has = same[poi[j].first];
					ans -= (has * (has - 1) / 2);
					same[poi[j].first] = 0;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}