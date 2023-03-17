#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		int n;
 		cin >> n ;
 		int a[n];
 		int ans=0;
 		for (int i=0; i<n ; i++){
 			cin >> a[i];
 			if(a[i]!=2)ans++;
 		}
 		cout << ans << en;
 	}	
    return 0;
}