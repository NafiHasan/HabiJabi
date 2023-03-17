#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	long long n;
 	cin >> n;
 	long long mn=LLONG_MAX, mx=0;
 	for(long long i=1; i*i*i <=n; i++){
 		if(n%i)continue;
 		for(long long j=i; j*j <=(n/i); j++){
 			if(n%j)continue;
 			long long k= n/(i*j);
 			if(n%k)continue;
 			if((i*j*k)==n){
 				mn=min(mn, (i+1) * (j+2) * (k+2));
 				mn=min(mn, (i+2) * (j+1) * (k+2));
 				mn=min(mn, (i+2) * (j+2) * (k+1));
 				mx=max(mx, (i+2) * (j+2) * (k+1));
 				mx=max(mx, (i+2) * (j+1) * (k+2));
 				mx=max(mx, (i+1) * (j+2) * (k+2));
 			}
 		}
 	}	
 	cout << mn-n << " " << mx-n << en;
    return 0;
}