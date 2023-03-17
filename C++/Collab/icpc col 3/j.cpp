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
 		int n,m;
 		cin >> n >> m;
 		if (n==-1 && m==-1)return 0;
 		if (n==m){
 			cout << "YES\n";
 			for (int i=1; i<n; i++)cout << i <<" " << i+1 <<en;
 			cout << n << " " << 1 << en;
 		}
 		else if (n*(n-1)/2 == m){
 			cout << "YES\n";
 			for (int i=1; i<n; i++){
 				for (int j=i+1; j<=n; j++)cout << i << " " <<j <<en;
 			}
 		}
 		else if (n%2==0 && (n/2)*(n/2)==m){
 			cout << "YES\n";
 			// for (int i)
 		}
 		else cout << "NO\n";
 	}	
    return 0;
}