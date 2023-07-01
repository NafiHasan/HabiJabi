#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
	string s;
 	cin >> s;
 	if(s.size() < 3)cout <<"YES\n";
 	else {
 		bool ok=1;
 		for (int i=2; i<s.size() ; i++){
 			int p1= s[i-2]-64 , p2=s[i-1]-64, now=s[i]-64;
 			int sum=p1+p2;
 			//cout << p1 <<" " << p2 <<en << now <<en;
 			while(now<sum-1)now+=26;
 			if(now+1 != sum){
 				ok=0;
 				break;
 			}
 		}
 		if(ok)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}