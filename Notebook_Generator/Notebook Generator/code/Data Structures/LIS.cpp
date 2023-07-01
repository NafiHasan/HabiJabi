int lis(vector<int> a) {
	int n = a.size();
	vector<int>d(n + 1, INF);
	d[0] = -INF;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j - 1] < a[i] and a[i] < d[j]) d[j] = a[i];
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] < INF) ret = i;
	return ret;
}