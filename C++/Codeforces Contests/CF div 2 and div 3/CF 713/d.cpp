#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		int n;
 		cin >> n;
 		ll a[n+2];
 		for(int i=0 ;i< n+2; i++)cin >> a[i];
 		sort(a,a+n+2);
 		ll sum=0;
 		for (int i=0; i<n+1; i++){
 			sum+=a[i];
 		}
 		int ind=-1;
 		for (int i=0; i<n+1; i++){
 			if(sum-a[i] == a[n+1]){
 				ind=i;
 				break;
 			}
 		}
 		if(ind != -1){
 			for (int i=0; i<n+1; i++){
 				if(ind != i)cout << a[i] << " ";
 			}
 			cout << en;
 		}
 		else {
 			// cout << sum <<en;
 			// sum=sum-a[n+1];
 			ll ne=0;
 			for (int i=0; i<n; i++)ne+=a[i];
 			if(ne == a[n]){
 				for(int i=0; i<n; i++)cout << a[i]<< " ";
 				cout << en;
 			}
 			else cout << "-1\n";
 		}
 	}	
    return 0;
}