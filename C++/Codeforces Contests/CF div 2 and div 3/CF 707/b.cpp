#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	w(t){
 		int n;
 		cin >>n;
 		int a[n],ans[n];
 		int cnt=0;
 		memset(ans,-1,sizeof(ans));
 		for (int i=0; i<n; i++)cin >>a[i];
 		for (int i=n-1; i>=0; i--){
 			if (a[i]>0){
 				ans[i]=1;
 				cnt--;
 				cnt=max(cnt,a[i]-1);
 			}
 			else if (cnt>0){
 				ans[i]=1;
 				cnt--;
 			}
 		}
 		for (int i=0; i<n; i++){
 			if (ans[i]==1)cout <<"1 ";
 			else cout << "0 ";
 		}
 		cout <<en;
 	}
    return 0;
}