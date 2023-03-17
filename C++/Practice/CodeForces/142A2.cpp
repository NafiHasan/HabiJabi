#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	long long  n;
 	cin >> n;
 	vector<long long>div;
 	for (long long i=1; i*i<=n; i++){
 		if(n%i==0){
 			div.push_back(i);
 			if(i != n/i)div.push_back(n/i);
 		}
 	}	
 	sort (div.begin(), div.end());
 	// for (int i=0; i<div.size(); i++) cout << div[i] << " ";
 	// cout << en;
 	long long sum= LLONG_MAX,a,b,c;
 	for (long long i=0; i<div.size(); i++){
 		if(div[i]*div[i]*div[i]>n)break;
 		for (long long j=i; j<div.size(); j++){
 			long long k=n/(div[i]*div[j]);
 			if(div[i]*div[j]*k == n){
 				a=div[i],b=div[j];
 				sum= min (sum , (a+1) * (b+2) * (k+2));
 				sum=min(sum, (b+1) * (k+2) * (a+2));
 				sum=min(sum, (k+1) * (a+2) * (b+2));
 				// a=div[i],b=div[j], c=k;
 			}
 		}
 	}
 	//cout << a <<" " << b << " " << c <<en;
 	long long mx=3LL*3LL*(n+1) -n;
 	// long long mn=(a+1)*(b+2)*(c+2)-n;
 	// mn=min(mn, (b+1) * (c+2) * (a+2));
 	// mn=min(mn, (c+1) * (a+2) * (b+2));
 	cout << sum-n << " " << mx << en;
    return 0;
}