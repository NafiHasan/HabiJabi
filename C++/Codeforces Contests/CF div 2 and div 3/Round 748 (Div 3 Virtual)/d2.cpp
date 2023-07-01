#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin>> n;
 		vector<ll>v(n);
 		int same  = 1, best  =0;
 		for (int i=0; i<n; i++)cin>> v[i];
 		sort (v.begin(), v.end());
 		for (int i=1; i<n; i++){
	 		if(v[i] != v[i-1])best = 1;
	 		else best++;
	 		same = max(same, best);
 	 	}
 	 	if(same >= n/2)cout << "-1\n";
 	 	vector<ll> dif(n-1);
 	 	for (int i=1; i<n; i++)dif[i-1] = v[i] - v[i-1];
 	 	int cnt = 0;
 		for (int i=0; i<n-1; i++){
 			if(v[i] == v[i+1])cnt++;
 			else {
 				int need = n/2 - cnt;
 				for (int j=i; j<dif.size(); j++){
 					
 				}
 			}
 		}
 	}	
    return 0;
}