template<typename T>
struct sparse_table {
	vector<T>ara;
	vector<int>logs;
	vector<vector<T>>table;
	sparse_table(int n) {
		ara.resize(n + 1);
		logs.resize(n + 1);
	}
	T func(T a, T b) { }
	void build(int n) {
		logs[1] = 0;
		for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
		table.resize(n + 1, vector<T>(logs[n] + 1));
		for (int i = 1; i <= n; i++) table[i][0] = ara[i];
		for (int j = 1; j <= logs[n]; j++) {
			int sz = 1 << j;
			for (int i = 1; i + sz - 1 <= n; i++)
				table[i][j] = func(table[i][j - 1], table[i + sz / 2][j - 1]);
		}
	}
	T query(int l, int r) {
		int d = logs[r - l + 1];
		return func(table[l][d], table[r - (1 << d) + 1][d]);
	}
};