#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
	int cnt=0;
 	for (int i=1; i<10; i++){
 		for (int j=1; j<10; j++){
 			for (int k=1; k<=(min(i,j)); k++){
 				// cout << i << " " << j << " " << k << en;
 				cnt++;
 			}
 		}
 	}	
 	cout<< cnt << en;
    return 0;
}