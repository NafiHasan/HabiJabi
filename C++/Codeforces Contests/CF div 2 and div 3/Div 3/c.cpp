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
 		string a,b;
 		cin >> a >> b;
 		int cnt=0 ,best=0;
 		for (int i=0; i<a.size(); i++){
 			for (int j=0; j<b.size(); j++){
 				if (b[j]==a[i]){
 					cnt=0;
 					for (int k=j,l=i; k<b.size() && l<a.size(); l++, k++){
 						if(a[l]==b[k]){
 							cnt++;
 							best=max(cnt,best);
 						}
 						else break;
 					}
 				}
 			}
 		}
 		int ans=0;
 		ans+=(int)a.size()-best;
 		ans+=(int)b.size()-best;

 		cout << ans <<en;
 	}	
    return 0;
}