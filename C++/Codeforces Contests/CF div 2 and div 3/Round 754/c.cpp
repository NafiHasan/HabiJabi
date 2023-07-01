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
 		cin >> n;
 		string s;
 		cin >> s;
 		vector<int>pos;
 		for (int i=0; i<n; i++)if(s[i] == 'a')pos.push_back(i);
 		bool found = 0;
 		int b = 0, c =0, ans = n+1;
 		if((int)pos.size() >= 2){
 			for (int i=0; i<pos.size()-1; i++){
 				b = 0, c= 0;
 				for (int j=pos[i]; j<=pos[i+1]; j++){
 					if(s[j] == 'b')b++;
 					else if(s[j] == 'c')c++;
 				}
 				if(b < 2 && c < 2)ans = min(ans,pos[i+1] - pos[i] + 1);
 			}
 		}
 		if(ans == 0 || ans == n+1)cout << "-1\n";
 		else cout << ans << '\n';

 	}	
    return 0;
}