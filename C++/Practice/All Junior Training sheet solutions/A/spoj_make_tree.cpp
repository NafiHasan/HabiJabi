#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int n, k;
 	cin >> n >> k;
 	vector<int>p(n + 1);
 	vector<vector<int> >v(k);
 	for (int i=1; i<=n ;i++)p[i] = i;
 	for (int i=1; i<=k; i++){
 		int cnt;
 		cin >> cnt;
 		for (int j=0; j<cnt; j++){
 			int x;
 			cin >> x;
 			v[i-1].push_back(x);
 			if(p[x] == x)p[x] = i;
 			else if(p[x] == p[i])p[x] = i;
 		}
 	}	
 	bool fo = 0, par;
 	for (int i=1; i<=n; i++){
 		if(p[i] == i && fo == 0){
 			p[i] = 0;
 			fo =1;
 			par = i;
 		}
 		else if(p[i] == i && fo == 1){
 			p[i] = par;
 		}
 	}
 	for (int i=0; i<k; i++){
 		for (int j=0; j<v[i].size(); j++){
 			if(p[i+1] == p[v[i][j]])p[v[i][j]] = i+1;
 		}
 	}
 	for (int i=1; i<=n; i++)cout << p[i]  << '\n';
    return 0;
}