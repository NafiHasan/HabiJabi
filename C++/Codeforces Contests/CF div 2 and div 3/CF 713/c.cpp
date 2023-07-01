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
 		int a, b;
 		cin >> a >>b;
 		int fina=a, finb=b;
 		string s;
 		cin >> s;
 		bool ans = 1;
 		int n= a+b;
 		for (int i=0; i<n; i++){
 			if (s[i] == '?' && s[i] != s[n-i-1]){
 				s[i] = s[n-i-1];
 				//cout << s[i] <<en;
 			}
 		}
 		for (int i=0; i<n; i++){
 			if (s[i] == '0')a--;
 			else if (s[i] == '1')b--;
 		}
 		for (int i = 0; i<n; i++){
 			if(a<=0 && b<=0)break;
 			if(s[i]=='?'){
 				if(a>b){
 					s[i]='0';
 					s[n-i-1]='0';
 					a--;
 					if(i != n-i-1)a--;
 				}
 				else {
 					s[i]='1';
 					s[n-i-1]='1';
 					b--;
 					if(i != n-i-1)b--;
 				}
 			}
 		}
 		int cnta=0,cntb=0;
 		for (int i=0; i<n; i++){
 			if(s[i] == '?'){
 				ans=0;
 				//cout << "f";
 				break;
 			}
 			else if(s[i] != s[n-i-1]){
 				ans=0;
 				//cout << "f";
 				break;
 			}
 			else if(s[i] == '0')cnta++;
 			else cntb++;
 		}
 		if(cnta != fina)ans=0;
 		if (cntb != finb)ans=0;
 		if(ans)cout << s << en;
 		else cout << "-1\n";
 	}	
    return 0;
}