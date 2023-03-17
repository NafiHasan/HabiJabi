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
 		vector<int> a(n);
 		map<int,int> mp;
 		int cnt = 0;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			if(mp[a[i]] == 0)cnt++;
 			mp[a[i]]++;
 		}
 		if(cnt == 2 && n > 2)cout << (n/2 + 1) << '\n';
 		else cout << n << '\n';
 	}	
    return 0;
}