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
 		cin >> n ;
 		string a, b;
 		cin >> a >> b;
 		int cnt=0,one=0,zero=0;
 		bool ans=1;
 		for (int i=0; i<n; i++){
 			if(a[i]=='0')one++;
 			else zero++;
 		}
 		for(int i=n-1; i>=0; i--){
 			bool dec=0;
 			if(a[i]=='0'){
 				one--;
 				dec=1;
 			}
 			if(cnt%2){
 				if(a[i]=='0')a[i]='1';
 				else a[i]='0';
 				//swap(one,zero);
 			}
 			if(a[i]!=b[i]){
 				if(dec)one++;
 				if(i%2 && one == ((i+1)/2)){
 					cnt++;
 					//a[i]=b[i];
 				}
 				else {
 					//cout<< i << " " << one << " ";
 					ans=0;
 					break;
 				}
 				if(dec)one--;
 			}
 		}
 		//for (int i=0; i<n; i++)if(a[i]!=b[i])ans=0;
 		if (ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}