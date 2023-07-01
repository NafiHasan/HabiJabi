#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		int home, k;
		cin >> home >> k;
		vector<pair<int,int>>mice(k);
		for (int i=0; i<k; i++){
			cin >> mice[i].second;
			mice[i].first = home- mice[i].second;
		}
		sort(mice.begin(), mice.end());
		int ans = 0;
		long long cnt = 0, cat =0;
		for (int i=0; i<k; i++){
			if(cat >= (long long)mice[i].second)break;
			cat += mice[i].first;
			ans++;
		}
		cout << ans << '\n';
	} 	
    return 0;
}