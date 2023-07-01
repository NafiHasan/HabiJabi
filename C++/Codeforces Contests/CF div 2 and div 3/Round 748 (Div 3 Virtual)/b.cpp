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
 		bool five = 0;
 		int ans1 =0, ans2 = 0;
 		for (int i= n-1 ; i>=0; i--){
 			if(s[i] == '5' && !five)five = 1;
 			else if(five && (s[i] == '2' || s[i] == '7')){
 				break;
 			}
 			else ans1++;
 		}
 		int z = 0, fou = 0;
 		for (int i= n-1; i>=0; i--){
 			if(s[i] == '0'){
 				z++;
 				if(z > 1)break;
 			}
 			else if(s[i] == '5' && z > 0)break;
 			else ans2++;
 		}
 		// cout << ans1  << ' ' << ans2 << ' ';
 		cout << min(ans1 , ans2) << '\n';
 	}	
    return 0;
}