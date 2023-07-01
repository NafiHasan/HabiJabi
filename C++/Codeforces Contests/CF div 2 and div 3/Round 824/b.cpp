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
 		for(int i=0; i<n; i++)cin >> a[i];
 		long long ans = 0;
 		long long cut = 2 * a[0] - 1;
 		for (int i=1; i<n; i++){
 			ans += (long long)a[i]/cut;
 			if(a[i] % cut == 0)ans--;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}