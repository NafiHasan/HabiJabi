#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool eq(vector<int> v) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j)continue;
			if (v[i] == v[j])return 1;
		}
	}
	return 0;
}

int main() {
	fast_io();
	int all = 0;
	map<vector<int>, int> mp;
	vector<vector<int>> vv;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			for (int k = 1; k < 7; k++) {
				for (int l = 1; l < 7; l++) {
					for (int m = 1; m < 7; m++) {
						for (int n = 1; n < 7; n++) {
							vector<int> tmp;
							tmp.push_back(i);
							tmp.push_back(j);
							tmp.push_back(k);
							tmp.push_back(l);
							tmp.push_back(m);
							tmp.push_back(n);
							if (eq(tmp))continue;
							int cnt = 0;
							vector<int> cn;
							for (int ind = 0; ind < 4; ind++) {
								if (tmp[ind] > tmp[ind + 1])cnt++;
								if (tmp[ind] > tmp[ind + 2])cnt++;
								if (tmp[ind + 1] > tmp[ind + 2])cnt++;
								cn.push_back(cnt);
								// cout << cnt << ' ';
								cnt = 0;
							}
							mp[cn]++;
							if (mp[cn] == 1) {
								vv.push_back(cn);
								// for (int in = 0; in < 4; in++)cout << cn[in] << ' ';
								// cout << "\n";
							}
							// cout << cnt << ' ';
							all++;
							// cout << "\n";
							// if (all % 4 == 0)cout << "\n";
						}
					}
				}
			}
		}
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] <<  ' ';
		}
		cout << "\n";
	}
	return 0;
}