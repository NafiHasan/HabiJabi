#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		priority_queue<pair<pair<long long,long long>,long long> , vector<pair<pair<long long,long long>,long long>>, greater<pair<pair<long long,long long>,long long>> > mina;
 		priority_queue<pair<pair<long long,long long>,long long> > maxb;
 		for (int i=0; i<n; i++){
 			long long a,b,c;
 			cin >> a >> b >> c;
 			mina.push({{a,b},c});
 			maxb.push({{b,a},c});
 			pair<pair<long long,long long>,long long> topa = mina.top(), topb = maxb.top();
 			if(topa.first.first == topb.first.second && topa.first.second == topb.first.first)cout << min(topa.second, topb.second) << '\n';
 			else cout << 
 		}
 	}	
    return 0;
}