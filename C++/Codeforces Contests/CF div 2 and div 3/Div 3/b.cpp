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
 		int n,k;
 		string s;
 		cin >> n >>k >> s;
 		int found =-1,last=0;
 		for (int i=0; i<s.size(); i++){
 			if (s[i]=='*' && found ==-1){
 				found =i;
 			}
 			if(s[i]=='*')last=i;
 		}
 		int cnt=1;
 		s[found]='x';
 		if(s[last]=='*'){
 			s[last]='x';
 			cnt++;
 		}
 		// cout << found <<" " << last <<en;
 		for (int i=found ; i<=last;){
 			int la=-1;
 			for (int j=i+1; j<=min(i+k,(int)s.size()-1); j++){
 				if(s[j]=='x'){
 					la=-1;
 					break;
 				}
 				if (s[j]=='*')la=j;
 			}
 			if(la!=-1 && s[la]=='*'){
 				cnt++;
 				i=la;
 				//cout << la <<en;
 			}
 			if(la==-1)break;
 		}
 		cout << cnt << en;
 	}	
    return 0;
}