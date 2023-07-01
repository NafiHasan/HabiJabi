#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		char c;
 		string s;
 		cin >> n >>c >> s;
 		bool same = 1;
 		for (int i=0; i<n; i++){
 			if(s[i]!= c){
 				same = 0;
 				break;
 			}
 		}
 		if(same == 1){
 			cout << "0\n";
 			continue;
 		}
 		bool yes = 0;
 		int ans = 0;
 		for (int i=1; i<n; i++){
			yes = 1;
 			for (int j=i-1; j<n; j+=i){
 				if(s[j] != c){
 					yes = 0;
 					break;
 				}
 			}
 			if(yes == 1){
 				ans = i;
 				break;
 			}
 		}
 		if(yes){
 			cout << "1\n";
 			cout << ans << '\n';
 		}
 		else {
 			bool same = 1;
 			for(int i=0; i<n-1; i++){
 				if(s[i] != c){
 					same =0;
 					break;
 				}
 			}
 			if(s[n-1] != c){	
 				if(same == 0){
 					cout << "2\n" << n-1 << ' '<< n << '\n';
 				}
 				else cout << "1\n" << n-1 << '\n';
 			}
 			else{
 				cout << "1\n" << n << '\n';
 			}
 		}
 	}	
    return 0;
}