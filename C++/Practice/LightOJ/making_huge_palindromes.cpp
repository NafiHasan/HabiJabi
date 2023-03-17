#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	for (int cs = 1; cs <= tc; cs++){
 		cout << "Case " << cs << ": ";
 		string s;
 		cin >> s;
 		int n = s.size();
 		string rev = s;
 		reverse(rev.begin(), rev.end());

 		int mod = 1e9 + 9, p = 31;
 		vector<long long> hash(n + 1 , 0), revHash(n + 1, 0), p_pow(n + 1, 1);

 		for (int i=1; i<=n; i++){
 			p_pow[i] = p_pow[i - 1] * p % mod;
 		}

 		// for (int i=0; i<n; i++){
 		// 	hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
 		// 	revHash[i + 1] = (revHash[i] + (rev[i] - 'a' + 1) * p_pow[i]) % mod;
 		// }
 		int ans = 0;
 		long long hash1 = 0, hash2 = 0;
 		for (int i=1; i<=n; i++){
 			hash1 = (p_pow[i - 1] * (s[n - i] - 'a' + 1) + hash1) % mod;
 			hash2 = (hash2 * 31 + (rev[i - 1] - 'a' + 1)) % mod;
 			// long long hash2 = (hash[n - 1] + mod - hash[n - i - 1]) % mod;
 			// cout << s.substr(n - i, i) << '\n';
 			// cout << hash1 << ' ' << hash2 << '\n';
 			if(hash1 == hash2)ans = max(ans, i);
 		}
 		ans = 2 * n - ans;
 		cout << ans << '\n';

 	}	
    return 0;
}