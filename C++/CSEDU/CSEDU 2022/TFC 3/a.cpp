#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<int,int>mm;
    mm[0] = -1;  
    int cnt0 = 0, cnt1 = 0;
    int ans = 0;
    for (int i=0; i<n; i++){
        if (s[i] == '0')cnt0++;
        else cnt1++;
        if (mm.find(cnt1 - cnt0) != mm.end()) ans = max(ans , i-mm[cnt1 - cnt0]);       
        else mm[cnt1-cnt0] = i;
    }
	cout << ans << '\n';
    return 0;
}