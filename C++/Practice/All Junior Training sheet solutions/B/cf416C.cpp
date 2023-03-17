#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.second >> a[i].first.first;
		a[i].second = i;
	}
	sort(a.rbegin(), a.rend());
	int k;
	cin >> k;
	vector<pair<int, int>> cap(k);
	for (int i = 0; i < k; i++) {
		cin >> cap[i].first;
		cap[i].second = i;
	}
	sort(cap.begin(), cap.end());
	int sum = 0;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			// bool found = 0;
			if (cap[j].first == -1)continue;
			if (a[i].first.second <= cap[j].first) {
				cap[j].first = -1;
				sum += a[i].first.first;
				ans.push_back({a[i].second, cap[j].second});
				break;
			}
		}
	}
	cout << ans.size() << ' ' << sum << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
	}
	return 0;
}