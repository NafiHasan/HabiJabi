#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	int n, k;
 	cin >> n >> k;
 	int a[n], ans=0;
 	for (int i=0; i<n; i++)cin >> a[i];
 	sort (a,a+n);
 	for (int i=0; i<k; i++)ans+=a[i];
 	cout << ans << en;	
    return 0;
}