/* z[i] denotes the maximum length of substring
* starting from position(i) which is also a prefix
* of the string
* call with Z zf(x) where x is the desired string*/
struct Z {
	int n; string s;
	vector<int>z;
	Z(const string &a) {
		n = a.size(); s = a; z.assign(n, 0);
	}
	void z_function() {
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r) z[i] = min (r - i + 1, z[i - l]);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
			if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		}
	}
};