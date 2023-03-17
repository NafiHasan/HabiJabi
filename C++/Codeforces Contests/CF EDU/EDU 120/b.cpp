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
 		vector<int>a(n), lik , dis;
 		map<int,int>m;
 		for (int i=0; i<n; i++)cin>> a[i];
 		string s;
 		cin >> s;
 		int cnt0 = 0;
 		for (int i=0; i<n; i++){
 			if(s[i] == '1') lik.push_back(a[i]);
 			else {
 				dis.push_back(a[i]);
 				cnt0++;
 			}
 		}
 		sort(lik.begin(), lik.end());
 		sort(dis.begin(), dis.end());
 		for (int i=0; i<dis.size(); i++)m[dis[i]] = i+1;
 		for (int i=0; i<lik.size(); i++)m[lik[i]] = cnt0 + i +1;
 		for (int i=0; i<n; i++) cout << m[a[i]] << ' ';
 		cout << '\n';
 	}	
    return 0;
}