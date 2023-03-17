#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	while(1){
 		int h,t;
 		cin >> h >>t;
 		if (h==0 && t==0)return 0;
 		if (h%2){
 			if (t==0){
 				cout << "-1\n";
 				continue;
 			}
 				int cnt=0;
 				while(t%4 != 2){
 					cnt++;
 					t++;
 				}
 				cnt+=(t/2);
 				h+=(t/2);
 				if (h%2){
 					cout << "-1\n";
 				}
 				else cout << cnt+(h/2) << en;
 		}
 		else {
 			if(t==0){
 				cout << h/2 << en;
 			}
 			else {
 				int cnt=0;
 				while(t%4){
 					cnt++;
 					t++;
 				}
 				h+=(t/2);
 				cnt+=(t/2);
 				cout << cnt+(h/2) <<en;
 			}
 		}
 	}	
    return 0;
}