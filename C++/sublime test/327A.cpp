#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
    file_io();
 	int n;
 	cin >> n;
 	int a[n];
 	for (int i=0; i<n; i++){
 		cin >> a[i];
 	}
 	int best=0, start=-1, end=-1, mx=0;
 	for (int i=0; i<n; i++){
 		if(a[i] == 0 ){
 			int last=i, cnt=0;
 			for (int j=i; j<n; j++){
 				if (a[j]==0)cnt++;
 				else cnt--;
 				if (cnt>best){
 					best=cnt;
 					last=j;
 				}
 				if (cnt<=0)break;
 			}
 			if (last-i+1 > mx){
 				mx=last-i+1;
 				start=i;
 				end=last;
 			}
 		}
 	}
 	for (int i=start; i<=end; i++){
 		if (start<0) break;
 		a[i]=1-a[i];
 	}
 	int ans=0;
 	if (start<0)ans--;
 	for (int i=0; i<n; i++)if (a[i]==1)ans++;
 	cout << ans << en;
    return 0;
}