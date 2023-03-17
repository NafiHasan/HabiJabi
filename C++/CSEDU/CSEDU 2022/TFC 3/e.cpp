#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main()
{
	fast_io();
	ll n, k;
 	cin >> n >> k;
 	if(k == 0){
 		for (int i=0; i<n; i++)cout << "()";
 		cout << '\n';
 		return 0;
 	}
 	if((n * (n-1) /2) < k){
 		cout << "Impossible\n";
 		return 0;
 	}
 	ll p = k * 2;
 	ll pp = sqrt(p);
	pp++;
 	p = pp;
 	if(p * (p-1)/2 < k)p++;
 	// cout << p << '\n';
 	vector<ll>all;
 	ll sum = 1;
 	all.push_back(1);
 	for (ll i=1; i<p-1; i++){
 		all.push_back(i);
 		sum += i;
 	}
 	for (ll i=1; i<all.size() && sum < k; i++){
 		all[i]++;
 		sum++;
 	}
 	// cout << all.size() << '\n';
 	string s = "";
 	int cnt = 0;
 	for (int i=0; i<=all.back(); i++){
 		s+= '(';
 		cnt++;
 	}
 	int nn = all.size() -1 ;
 	for (ll i=nn; i>=0; i--){
 		if(i == nn)s+=')';
 		else if(i != nn && all[i+1] != all[i])s+=')';
 		else if(i != nn && all[i+1] == all[i]) {
 			s+="()";
 			cnt++;
 		}
 	}
 	s+=')';
 	for (int i=cnt + 1; i<=n; i++)s+="()";
 	cout << s << '\n';
    return 0;
}