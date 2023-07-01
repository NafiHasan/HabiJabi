#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen ("input.in", "r", stdin);
	freopen ("output.in", "w", stdout);
	#endif
}

int main()
{
    file_io();
 	w(t){
 		int n,k;
 		string s;
 		cin >> n>> k >> s;
 		int half=(n-1)/2;
 		// if (n%2==0 && k==half){
 		// 	cout <<"NO\n";
 		// }
 		// else if (k==0){
 		// 	cout <<"YES\n";
 		// }
 		// else {
 			bool ok=1;
 			int cnt=0;
 			for (int i=0; i<half; i++){
 				if (s[i]==s[n-i-1]){
 					cnt++;
 				}
 				else break;
 			}
 			if (cnt<k)ok=0;
 			if (ok) cout <<"YES\n";
 			else cout <<"NO\n";
 		// }
 	}
    return 0;
}