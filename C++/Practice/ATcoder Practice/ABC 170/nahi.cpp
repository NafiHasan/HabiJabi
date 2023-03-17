#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	int ans;
 	for (int i=1300450; i<=1399459; i++){
 		if (i%792==0){
 			string s=to_string(i);
 			if (s[0]=='1' && s[1]=='3' && s[4]=='4' && s[5]=='5'){
 				ans=i;
 				break;
 			}
 		}
 	}	
 	cout << ans <<en;
    return 0;
}