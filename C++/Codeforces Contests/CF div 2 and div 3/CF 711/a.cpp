#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int g(ll n){
	ll tmp=n;
	ll sum=0;
	while(tmp){
		sum+=tmp%10;
		tmp/=10;
	}
	if(__gcd(n,sum)>1)return 1;
	else return 0;
}

int main()
{
	fast_io();
	w(t){
		ll n;
		cin >> n;
		while(1){
			if(g(n)==1)break;
			n++;
		}
		cout<< n << en;
	}
    return 0;
}