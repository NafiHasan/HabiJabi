#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
    file_io();
 	int n;
 	cin >> n;
 	int a[n] , ans=0;
 	for (int i=0; i<n; i++){
 		cin >> a[i];
 		if (a[i]==i)ans++;
 	}
 	bool ok=0;
 	for (int i=0; i<n; i++){
 		if (a[i]!=i && a[a[i]]==i){
 			ok=1;
 		}
 	}
 	if (ok)cout << min(ans+2,n) << en;
 	else cout << min(ans+1, n) << en;
    return 0;
}