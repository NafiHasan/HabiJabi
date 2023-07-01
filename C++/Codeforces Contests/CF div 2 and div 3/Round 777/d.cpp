#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

vector<ll> dd;
int cn = 0;
bool beauty(ll num, ll d);

bool chk(ll num, ll d) {
	cn++;
	if (num % d != 0)return 0;
	// if (num == 16)cout << "c";
	for (ll i = d; i <= num; i += d) {
		if (num % i == 0) {
			ll div = num / i;
			if (beauty(div, d)) {
				dd.push_back(i);
				// dd.push_back(div);
				return 1;
			}
		}
	}
	return 0;
}


bool beauty(ll num, ll d) {
	cn++;
	if (num % (d * d) != 0) {
		dd.push_back(num);
		return 1;
	} else {
		return chk(num, d);
	}
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, d;
		cin >> n >> d;
		int cnt = 0;
		map<vector<ll>, ll>mp;
		vector<ll> div;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				div.push_back(i);
				div.push_back(n / i);
			}
		}
		for (int i = 0; i < div.size(); i++) {
			if (cnt > 1)break;
			if (div[i] % d == 0 && div[i] % (d * d) != 0) {
				dd.clear();
				ll got = n / div[i];
				if (got % d == 0) {
					// if (div == 16)cout << "nafI";
					dd.push_back(div[i]);
					if (beauty(got, d)) {
						// cout << got << ' ' << div << '\n';
						for (int i = 0; i < dd.size(); i++)cout << dd[i] << ' ';
						cout << " end\n";
						sort(dd.begin(), dd.end());
						if (mp[dd] == 0) {
							cnt++;
							// cout << got << " got " << div << "\n";
							mp[dd]++;
							// for (int i = 0; i < dd.size(); i++) {
							// 	cout << dd[i] << ' ';
							// }
							// cout << " got end \n";
						}
					}
				}
			}
		}
		// while (cnt < 2) {
		// 	cn++;


		// 	div++;
		// }
		// cout << cn << '\n';
		if (cnt > 1)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}