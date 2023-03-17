#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int n;
 	cin >> n;
 	int ans1=INT_MAX, ans2=0, mina,minb, minc, maxa,maxb,maxc;
 	for (int i=2; i<=n+1; i++){
 		for (int j=3; j<=n+2; j++){
 			for (int k=3; k<=n+2; k++){
 				if((i-1)*(j-2)* (k-2) == n){
 					if(ans1> i*j*k-n){
 						ans1=i*j*k-n;
 						mina=i,minb=j,minc=k;
 						// cout << "mini ";
 						// cout << i-1 << " " << j-2 << " " << k-2 <<en;
 					}
 					if(ans2<i*k*j-n){
 						ans2=i*k*j-n;
 						maxa=i, maxb=j, maxc=k;
 						// cout << "maxi ";
 						// cout << i-1 << " " << j-2 << " " << k-2 <<en;
 					}
 					cout << i-1 << " " << j-2 << " " << k-2 <<en;
 				}
 			}
 		}
 	}
 	cout << en <<"min " << mina-1 << " " << minb-2 << " " << minc-2 <<en;	
 	cout << "max " << maxa-1 << " " << maxb-2 << " " << maxc-2 <<en;	
 	cout << ans1 << " " << ans2 << en;
    return 0;
}