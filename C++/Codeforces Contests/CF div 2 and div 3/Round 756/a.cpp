#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int n = s.size();
		int ans = -1;
		if((s[n-1]-'0') % 2 == 0)ans = 0;
		for (int i=0; i<n; i++){
			if(ans == 0)break;
			int num = s[i] - '0';
			if(num %2 == 0){
				ans = 2;
				break;
			}
		}
		if(ans != 0 && (s[0] - '0') %2 == 0)ans = 1;
		cout << ans << '\n';
	}	
    return 0;
}