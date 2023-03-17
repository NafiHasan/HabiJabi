#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	ll n;
 	cin >> n;
 	vector<pair<ll,ll>>v1(n),v2(n);
 	map<pair<ll,ll>,ll>m;
 	for (int i=0; i<n; i++)cin >> v1[i].first ;	
 	for (int i=0; i<n; i++)cin >> v1[i].second ;
 	for (int i=0; i<n; i++){
 		v2[i].first=v1[i].second;
 		v2[i].second=v1[i].first;
 		m[{v1[i].first,v1[i].second}]++;
 	}
 	sort(v1.rbegin(), v1.rend());
 	sort(v2.rbegin(),v2.rend());
 	ll ans=0LL;
 	int i=0,j=0,cur=1;
 	ll num=n;
 	bool brk=0;
 	while(num!=0LL){
 		if(cur==1){
 			while(m[{v1[i].first,v1[i].second}]==0){
 				i++;
 				if(i>=(int)n){
 					num=0LL;
 					brk=1;
 					//cout << "c " << i <<en;
 					break;
 				}
 			}
 			cout << i << en;
 			if(brk)break;
 			m[{v1[i].first,v1[i].second}]--;
 			cur++;
 			//cout << v1[i].first << " v1 " << v1[i].second <<en;
 		}
 		else {
 			while(m[{v2[j].second,v2[j].first}]==0){
 				j++;
 				if(j>=(int)n){
 					num=0LL;
 					brk=1;
 					//cout <<"c " << j <<en;
 					break;
 				}
 			}
 			cout << j <<en;
 			if(brk)break;
 			ans+=v2[j].first;
 			m[{v2[j].second,v2[j].first}]--;
 			cur--;
 			//cout << v2[j].second << " v2 " << v2[j].first <<en;
 		}
 		//cout << i <<" " << j <<en;
 	}
 	cout << ans <<en;
    return 0;
}