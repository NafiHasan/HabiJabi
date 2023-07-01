#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	string s, sorted, ans;
 	cin >> s;
 	sorted = s;
 	int n = s.size();
 	sort(sorted.begin(), sorted.end());
 	ans = sorted;
 	for (int i=0, l = 0, j = n-1; i<n; i++){
 		if(i%2 && s[i] == s[i-1]){
 			ans[j--] = sorted[i];
 		}
 		else ans[l++] = sorted[i];
 	}
 	// cout << ans << '\n';
 	for (int i=0,j = n-1; i<(n+1)/2; j--,i++)if(ans[i]!= ans[j])ans[j] = ans[i];
 	cout << ans << '\n';
    return 0;
}