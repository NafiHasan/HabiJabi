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
 		cin>> s;
 		int ans = -1;
 		bool ok = 0;
 		for (int i=0; i<n - 1; i++){
 			if(s[i] == 'R' && s[i + 1] == 'L')ok = 1;
 			if(s[i] == 'L' && s[i + 1] == 'R')ans= i + 1;
 		}
 		if(ok)cout << "0\n";
 		else cout << ans << '\n';
 	}	
    return 0;
}