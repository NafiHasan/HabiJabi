#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		cin >> n >> k;
 		char a[n][n];
 		for (int i=0; i<n; i++){
 			for (int j=0; j<n; j++)a[i][j] = '.';
 		}
 		map<int,int>ro, co;
 		int cnt = 0;
 		for (int i=0; i<n; i++){
 			if(ro[i] > 0)continue;
 			for (int j=0; j<n ;j++){
 				if(co[j] > 0 || ro[i] > 0)continue;
 				a[i][j] = 'R';
 				cnt++;
 				if(cnt == k){
 					i = n+1;
 					j= n+1;
 					break;
 				}
 				ro[i]++;
 				ro[i-1]++;
 				ro[i+1]++;
 				co[j]++;
 				co[j-1]++;
 				co[j+1]++;
 			}
 		}
 		if(cnt != k){
 			cout << "-1\n"; 
 		}
 		else {
 			for (int i=0; i<n; i++){
 				for (int j=0; j<n; j++)cout << a[i][j];
 				cout << '\n';
 			}
 		}
 	}
    return 0;
}