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
 	int mat[n][n];
 	memset(mat,0,sizeof(mat));
 	stack<pair<int,int>>s1,s2;
 	for (int i=0,j; i<n; i++){
 		if(i%2)j=1;
 		else j=0;
 		for (; j<n; j+=2){
 			s1.push({i+1,j+1});
 		}
 	}
 	for (int i=0,j; i<n; i++){
 		if(i%2)j=0;
 		else j=1;
 		for (; j<n; j+=2){
 			s2.push({i+1,j+1});
 		}
 	}
 	for(int i=0; i<n*n; i++){
 		int a;
 		cin >>a;
 		if(a==1 || a==3){
 			if(!s2.empty()){
 				cout << 2 << " " << s2.top().first << " " << s2.top().second << endl ;
 				s2.pop();
 			}
 			else {
 				if(a==1)cout << 3 << " " << s1.top().first << " " << s1.top().second << endl;
 				else cout << 1 << " " << s1.top().first << " " << s1.top().second << endl;
 				s1.pop();
 			}
 		}
 		else {
 			if(!s1.empty()){
 				cout << 1 << " " << s1.top().first << " " << s1.top().second << endl ;
 				s1.pop();
 			}
 			else {
 				cout << 3 << " " << s2.top().first << " " << s2.top().second << endl ;
 				s2.pop();
 			}
 		}
 	}
    return 0;
}