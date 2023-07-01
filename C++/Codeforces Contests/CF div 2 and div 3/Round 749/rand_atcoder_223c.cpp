#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int n;
	cin >> n;
	vector<pair<int,int>>v(n);
 	for  (int i=0; i<n; i++){
 		cin >> v[i].first >> v[i].second;
 	}	
 	int l = 0, r = n-1, lc = 0, rc = 0;
 	while(l < r){
 		if(lc > v[l].first)
 	}
    return 0;
}