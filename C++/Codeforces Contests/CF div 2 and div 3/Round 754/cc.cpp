#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	int _2;
 	_2 = 2;
 	while(tc--){
 		int n;
 		string s;
 		cin >> n >> s;
 		vector<int>pos;
 		for (int i=0; i<n; i++)if(s[i] == 'a')pos.push_back(i);
 		int last = 0, a = 0,b = 0, c = 0, ans = n+2;
 		for (int i=0;i <n; i++){
 			if(s[i] == 'a'){
 				a++;
 				if(a > 1 && b < 2 && c < 2){
 					ans = min(ans,i-last+1);
 				}
 				a = 1;
 				b = 0, c= 0;
 				last = i;
 			}
 			else if(s[i] == 'b')b++;
 			else c++;
 		}
 		if(ans > 1 && ans < n+1)cout << ans << '\n';
 		else cout << "-1\n";
 	}	
    return 0;
}