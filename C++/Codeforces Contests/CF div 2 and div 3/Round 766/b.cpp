#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin >> n >> m;
 		n--, m--;
 		vector<int>d;
 		for (int i=0; i<=n; i++){
 			for (int j=0; j<=m; j++){
 				int mx = i - 0 + j - 0;
 				mx = max(mx, abs (i - n) + abs(j - m));
 				mx = max(mx, i + abs(j - m));
 				mx = max(mx, abs(i - n) + j);
 				d.push_back(mx);
 			}
 		}
 		sort(d.begin(), d.end());
 		for (int i=0; i<d.size(); i++)cout << d[i] << ' ';
 		cout << '\n';
 	}	
    return 0;
}