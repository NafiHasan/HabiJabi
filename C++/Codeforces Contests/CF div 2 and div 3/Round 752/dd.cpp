#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long a, b;
 		cin >> a >> b;
 		if(a == b)cout << a << '\n';
 		else if(a < b){
 			long long div = b/a;
 			long long ans = a* div;
 			ans += (b - ans)/2;
 			cout << ans << '\n';
 		}
 		else cout << a + b << '\n';
 	}
    return 0;
}