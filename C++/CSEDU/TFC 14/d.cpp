#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		ll n,k;
 		cin>> n >> k;
 		ll a[n], b[n];
 		map<int,int>m;
 		for (int i=0; i<n; i++){
 			cin >>a[i];
 			m[a[i]]++;
 		}
 		vector<ll>numb,numa;
 		for (int i=0; i<n; i++){
 			cin >> b[i];
 			if(m[b[i]]==0)numb.push_back(b[i]);
 			else m[b[i]]--;
 		}
 		for (int i=0; i<n; i++){
 			if(m[a[i]]){
 				numa.push_back(a[i]);
 				m[a[i]]--;
 			}
 		}
 		if((int)numa.size()==0 && (int)numb.size()==0)cout << "YES\n";
 		else if((int)numa.size()==1 && (int)numb.size()==1){
 			if(abs(numa[0]-numb[0])<=k)cout << "YES\n";
 			else cout << "NO\n";
 		}
 		else cout << "NO\n";
 	}
    return 0;
}