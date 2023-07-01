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
 		char a[n][n];
 		int x1=-1,x2,y1,y2;
 		for (int i=0; i<n; i++){
 			string s;
 			cin >> s;
 			for (int j=0; j<n; j++){
 				a[i][j]=s[j];
 				if(s[j]=='*' && x1 == -1){
 					x1=i,y1=j;
 				}
 				else if (s[j] == '*'){
 					x2=i,y2=j;
 				}
 			}
 		}
 		if(x1 == x2){
 			if(x1==0){
 				a[x1+1][y1]='*';
 				a[x1+1][y2]='*';
 			}
 			else {
 				a[x1-1][y1]='*';
 				a[x1-1][y2]='*';
 			}
 		}
 		else if (y1==y2){
 			if(y1==0){
 				a[x1][y1+1]='*';
 				a[x2][y1+1]='*';
 			}
 			else {
 				a[x1][y1-1]='*';
 				a[x2][y2-1]='*';
 			}
 		}
 		else {
 			a[x1][y2]='*';
 			a[x2][y1]='*';
 		}
 		for (int i=0; i<n; i++){
 			for (int j=0; j<n; j++)cout << a[i][j];
 			cout << en;
 		}
 	}	
    return 0;
}