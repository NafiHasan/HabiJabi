#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >>tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<long long>v(n);
 		map<long long , int> cnt;
 		long double sum = 0, avg;
 		for (int i=0; i<n ;i++){
 			cin >> v[i];
 			sum += v[i];
 			cnt[v[i]]++;
 		}
 		sum *= 2.0;
 		avg = sum / n;
 		long long av = avg;
 		if(abs((double)av - avg) > 1e-9){
 			cout << "0\n";
 			continue;
 		}
 		// cout << avg << '\n';
 		// cout << av << '\n';
 		sort(v.begin(), v.end());
 		long long ans = 0;
 		for (int i=0; i<n-1; i++){
 			// if(v[i] > av/2)break;
 			cnt[v[i]]--;
 			ans+= cnt[av - v[i]];
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}