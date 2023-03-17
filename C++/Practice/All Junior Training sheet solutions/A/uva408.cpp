#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	// fast_io();
	int st, mod;
 	while(1){
 		cin >> st >> mod;
 		if(feof(stdin))break;
 		vector<int>dp(mod,0);
 		map<int,int>m;
 		dp[0] = 0;
 		m[0]++;
 		for (int i=1; i<mod; i++){
 			dp[i] = (dp[i-1] + st) % mod;
 			m[dp[i]]++;
 		}
 		bool ans = 1;
 		for (int i=0; i<mod; i++)if(m[i] == 0)ans = 0;
 		printf("%10d%10d    ",st, mod);
 		if(ans)cout << "Good Choice\n\n";
 		else cout << "Bad Choice\n\n";
 	}	
    return 0;
}