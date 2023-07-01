#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

vector<ll>di;

ll sum(ll num){
	ll ans=1LL+num;
	ll st=2;
	for (ll i=0; i<di.size(); i++){
		if(di[i]>100){
			st=di[i];
			break;
		}
		if(num % di[i] ==0 ){
			ans+=di[i];
			if((num/di[i]) != di[i])ans+=num/di[i];
		}
	}
	for (ll i=st; i*i <= num ; i+=st-1){
		if(num%i==0){
			ans+=i;
			if((num/i) != i)ans+=num/i;
		}
	}
	return ans;
}

int main()
{
	fast_io();
 	vector<bool>prime(10000005,1);
 	prime[1]=0;
 	// di.push_back(2);
 	for (int i=2; i*i <= 10000005; i++){
 		if(prime[i] == 0)continue;
 		di.push_back(i);
 		for (int j=i*i; j<=10000005; j+=i)prime[j]=0;
 	}		
 	map<ll,ll>m;
 	// vector <ll>fun(10000005);
 	m[1]=1;
 	for (ll i=2; i<1000005; i++){
 		if(prime[i]){
 			ll p=i+1;
 			if(m[p]==0)m[p]=i;
 		}
 		else {
 			ll p= sum(i);
 			if(m[p]==0)m[p]=i;
 			// if(p>10000)cout << p << en;
 		}
 	}
 	w(t){
 		ll n;
 		cin >> n;
 		if(m[n]==0){
 			cout << "-1\n";
 		}
 		else cout << m[n] <<en; 
 	}
    return 0;
}