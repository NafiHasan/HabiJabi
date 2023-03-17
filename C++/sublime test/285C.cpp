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
 	ll a[n],ans=0;
 	for (int i=0; i<n ;i++)cin >> a[i];
 	sort (a,a+n);
 	for (int i=0; i<n; i++){
 		ans+=abs(a[i]-(i+1));
 	}
 	cout << ans << en;
    return 0;
}