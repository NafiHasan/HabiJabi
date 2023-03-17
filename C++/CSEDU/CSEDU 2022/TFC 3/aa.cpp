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
 	int cnt0 = 0, cnt1 = 0, pre = 0, ans  =0;
 	int chn = 0;
 	for (int i=0; i<n; i++){
 		if(i && s[i] != s[i-1])chn++;
 		if(chn > 1){
 			if(cnt1 == cnt0){
 				pre += cnt1 + cnt0;
 				ans = max(ans, pre);
 			}
 			else {
 				pre = 0;
 				ans =max (ans, min(cnt1, cnt0));
 			}
 			cnt0 =0, cnt1 = 0;
 			chn = 0;
 		}
 		if(s[i] == '0')cnt0++;
 		else cnt1++;
 		if(cnt0 == cnt1)ans = max(ans, pre + cnt0 + cnt1);
 		ans = max(ans, min(cnt1, cnt0));
 	}
 	cout << ans << '\n';
    return 0;
}