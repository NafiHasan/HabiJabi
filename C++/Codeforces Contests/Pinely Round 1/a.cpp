#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, a, b;
 		cin >> n >> a >> b;
 		if(n == a && n == b) cout << "YES\n";
 		else if((n - a - b) > 1)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}