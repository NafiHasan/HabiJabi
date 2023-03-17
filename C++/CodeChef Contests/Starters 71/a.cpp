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
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			mp[a[i]]++;
 		}
 		if(n % 2 == 1){
 			cout << "NO\n";
 			continue;
 		}
 		bool ok = 1;
 		for (int i=0; i<n; i++){
 			if(mp[a[i]] % 2){
 				ok =0;
 				break;
 			}
 		}
 		if(ok)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}