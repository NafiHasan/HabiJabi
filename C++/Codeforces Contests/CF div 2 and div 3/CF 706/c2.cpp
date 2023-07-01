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
 	w(t){
 		int n;
 		cin >> n;
 		long double ans=0.0;
 		vector<ll>a;
 		vector<ll>b;
 		for (int i=0; i<2*n; i++){
 			ll x,y;
 			cin >>x>>y;
 			if (x==0) a.push_back(abs(y));
 			else b.push_back(abs(x));
 		}
 		sort (a.begin(),a.end());
 		sort (b.begin(),b.end());
 		//for (int i=0; i<n; i++)cout <<a[i] <<" "<<b[i]<<en;
 		for (int i=0; i<n; i++){
 			ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
 			//cout <<sqrt(a[i]*a[i]+b[i]*b[i]) <<en;
 		}
 		cout <<fixed <<setprecision(12) <<ans<<en;
 	}
    return 0;
}