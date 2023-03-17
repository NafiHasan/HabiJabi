#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int n,w;
 	cin >> n >> w;
 	vector<long long> dp(w+1,0);
 	for (int i=0; i<n; i++){
 		long long weight, val;
 		cin >> weight >> val;
 		for (int j=w-weight; j>=0; j--){
 			dp[j+weight]=max(dp[j+weight], dp[j]+val);
 		}
 	}	
 	cout << *max_element(dp.begin(), dp.end()) << en;
    return 0;
}