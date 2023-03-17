#include <bits/stdc++.h>  
 
using namespace std;
 
typedef unsigned long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)


int main()
{
	fast_io();
 	int cs=1;
 	w(t){
 		ll a, b , m;
 		cin >> a >> b >> m;
 		if(b<a)swap(a,b);
 		ll dif=(b-a);
 		vector<ll>primes;
 		cout << "Case " << cs++ << ": ";
 		if(dif==0){
 			cout << "0\n";
 		}
 		else{
 			if (dif % 2LL == 0) 
 	        primes.push_back(2LL);
	    	while(dif % 2LL == 0)dif/=2LL;
 	    	for (ll i = 3; i * i <= dif; i += 2) {
 	     		if (dif % i == 0) 
 		        	primes.push_back(i);
		    	while(dif % i == 0)dif/=i;
 	    	}
 			if (dif > 1)
	        	primes.push_back(dif);
	    	//for (int i=0; i<primes.size(); i++) cout << primes[i]<< " ";
	    	ll cnt=0,ss=primes.size();
	    	vector<ll>pro[ss+1];
	    	int f=0;
	    	// for (int i=1; i<=ss; i++){
	    	// 	ll p=0;
	    	ll num= (1 << ss);
	    	num--;
	   		for (int j=1; j<=num; j++){
	   			ll pr=1;
	   			for (int k=0; k<ss; k++){
	   				//cout << j << " j\n";
    				if((1 << k) & j){
       					//cout << (1<<k) << en<< num << en;
    					f++;
    					pr*=primes[k];
    					// cout << pro <<" ";
    				}
	    		}
	    		pro[__builtin_popcount(j)].push_back(pr);
	    	}
	   	// }
	  		// int f=0;
	   		for (int i=1; i<=primes.size(); i++){
	   			ll p=0;
	   			for (int j=0; j<pro[i].size(); j++){
	   			//f++;
	   				p+=(m+a)/pro[i][j];
	   				p-=a/pro[i][j];
	   			}
	   			if(i%2)cnt+=p;
	   			else cnt-=p;
	   		}
	    	// cout << f << en;
	   	if(__gcd(a,b)==1LL)cnt--;
	   	cout << m-cnt << en;
 		}
 	}	
    return 0;
}