#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define in long long
in h, w, n;

bool valid(in r, in c){
	if(r < 0 || c < 0)return 0;
	if(r + 2 >= h || c + 2 >= w)return 0;
	return 1;
}

int main()
{
	fast_io();
 	cin >> h >> w >> n;
 	vector<pair<in,in>>cl(n);
 	for (in i=0; i<n; i++){
 		cin >> cl[i].first >> cl[i].second;
 		cl[i].first--, cl[i].second--;
 	}	
 	map<in,in>ans;
 	map<pair<in,in>, in>cnt;
 	for (in i=0; i<n; i++){
 		in ro = cl[i].first, col = cl[i].second;
 		for (in rr = ro-2; rr <= ro; rr++){
 			for (in cc= col-2; cc <=col; cc++){
 				if(valid(rr,cc)){
 					ans[cnt[{rr,cc}]]--;
 					cnt[{rr,cc}]++;
 					ans[cnt[{rr,cc}]]++;
 				}
 			}
 		}
 	}
 	ans[0] += (h-2) * (w-2);
 	for (in i=0; i<10; i++){
 		cout << ans[i] << '\n';
 	}
    return 0;
}