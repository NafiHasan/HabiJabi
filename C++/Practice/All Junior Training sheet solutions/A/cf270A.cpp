#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const double eps = 1e-9;


int main()
{
	fast_io();
	vector<int>a;
 	for (int i=3; i<=360; i++){
 		if(360 % i != 0)continue;
 		a.push_back(180- (360/i));
 	}	
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int x;
 		cin>> x;
 		bool ans = 0;
 		for (int i=0; i<a.size(); i++){
 			if(a[i] == x) ans = 1;
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}
    return 0;
}