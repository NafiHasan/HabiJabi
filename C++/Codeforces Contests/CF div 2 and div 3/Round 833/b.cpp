#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		string s;
 		cin >> s;
 		long long ans = 0;
 		vector<int> cnt(12, 0);
 		int dist = 0;
 		for (int i=0; i<n; i++){
 			if(cnt[s[i] - '0'] == 0) dist++;
 			cnt[s[i] - '0']++;
 			int last = min(n - 1, i + 81);
 			if(i){
 				cnt[s[i - 1] - '0']--;
 				if(cnt[s[i - 1] - '0'] == 0)dist--;
 			}
 			vector<int> tmp(12,0);
 			tmp = cnt;
 			int mx = cnt[s[i] - '0'];
 			int tmp2 = dist;
			int sz = last - i + 1;
			if(mx <= tmp2)ans++;
 			for (int k=i + 1; k< min(n, i + 102); k++){
 				// pigeonhole principle. 
 				// as there are 10 digits. for 102 characters, there must be a character with more than 10 occurence. so no need to count further
 				tmp[s[k] - '0']++;
 				if(tmp[s[k] - '0'] == 1)tmp2++;
 				mx = max(mx, tmp[s[k] - '0']);
 				if(mx <= tmp2)ans++;
			}
 		}
 		cout << ans << '\n';
 	}
    return 0;
}