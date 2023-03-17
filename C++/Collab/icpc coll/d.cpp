#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int cs=1;
 	w(t){
 		ll n;
 		cin >> n;
 		ll a[n];
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 		}
 		sort(a,a+n);
 		ll sum=0;
 		sum=a[0]+a[1]+1;
 		ll avg=0, cnt=0;
 		for (int i=2; i<n; i++){
 			if (a[i]+1 > ((sum+avg)/(cnt+1LL)))break;
 			avg+= a[i]+1LL;
 			cnt++;
 		}
 		sum=min(sum,(sum+avg)/(cnt+1LL));
 		cout << "Case #" << cs++ << ": " <<sum << en;
 	}	
    return 0;
}