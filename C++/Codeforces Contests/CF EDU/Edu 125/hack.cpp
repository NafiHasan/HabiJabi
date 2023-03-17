#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		string str;
		cin >> str;
		ll res[2] = {};
		ll i = 0;
		while (i < n) {
			if (i + 1 >= n) break;
			if (str[i] == ')') {

				// we must find the next ')'
				ll j = i + 1;
				while (j + 1 < n && str[j] != ')') j++;
				if (str[j] != ')') break;

				res[0]++;
				res[1] += j - i + 1;
				i = j + 1;
			} else if (str[i] == '(') {
				// in either case the prefix is good
				res[0]++;
				res[1] += 2;
				i += 2;
			}
		}
		cout << res[0] << " " << n - res[1] << "\n";
	}

}