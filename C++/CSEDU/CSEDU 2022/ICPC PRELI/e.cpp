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
 		vector<ll>a;
 		ll sum=0LL;
 		ll mx=LLONG_MIN;
 		for (ll i=0LL; i<n; i++){
 			ll x;
 			cin >> x;
 			if(x>0)a.push_back(x);
 			else if(x<0 && (int)a.size()>0){
 				if(a.back()>0) a.push_back(x);
 			}
 			if(x>0)sum+=x;
 			mx=max(mx,x);
 		}
 		//cout << a.back();
 		if(sum == 0LL){
 			sum=mx;
 		}
 		int cnt=0;
 		// if((int)a.size() > 2){
 			for (int i=1; i<(int)a.size()-1; i++){
 				//cout << i <<en;
 				if(a[i] < 0LL && a[i-1] > 0LL && a[i+1] >0LL)cnt++;
 			}
 		// }
 		cout << "Case " << cs++ << ": " << sum << " " << cnt <<en;
 	}	
    return 0;
}