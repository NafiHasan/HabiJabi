#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<bool>prime(N+1, 1);

void sieve(){
	prime[0] = prime[1] = 0;
	for (int i=2; i*i <= N; i++){
		if(!prime[i])continue;
		for (int j = i*i ; j <= N; j+=i)prime[j] = 0;
	}
}

int main()
{
	fast_io();
	sieve();
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>v(n);
		int sum = 0;
		for (int i=0; i<n; i++){
			cin >> v[i];
			sum+= v[i];
		}
		if(prime[sum]){
			int left;
			for (int i=0; i<n; i++){
				if(!prime[sum - v[i]]){
					left = i+1;
					break;
				}
			}
			cout << n-1 << '\n';
			for (int i=1; i<=n; i++){
				if(i!= left)cout << i << ' ';
			}
			cout << '\n';
		}
		else {
			cout << n << '\n';
			for (int i=1; i<=n; i++)cout << i << ' ';
			cout << '\n';
		}
	}	
    return 0;
}