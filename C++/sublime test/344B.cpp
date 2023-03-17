#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
    file_io();
 	int a, b , c;
 	cin >> a >> b >> c;
 	int ans1=0, ans2=0, ans3=0;
 	int mx=max(a,max(b,c)),mn= min(a,min(b,c));
 	int mid=(a+b+c)-mn-mx;
 	bool ok=false;
 	while(mn+mid>=mx){
 		if (a==b && b==c && a%2==0){
 			ok=true;
 			ans1+=a/2, ans2+=a/2, ans3+=a/2;
 			break;
 		}
 		else if (a==b && b==c && a%2 == 1){
 			ok = 0;
 			break;
 		}
 		if (a>=b && a>=c && a){
 			if (b >=c && b){
 				a--, b--;
 				ans1++;
 			}
 			else {
 				a--, c--;
 				ans3++;
 			}
 		}
 		else if (b >= a && b >=c){
 			if (a >= c){
 				a--,b--;
 				ans1++;
 			}
 			else {
 				c--, b--;
 				ans2++;
 			}
 		}
 		else {
 			if(a >= b){
 				a--, c--;
 				ans3++;
 			}
 			else {
 				b--, c--;
 				ans2++;
 			}
 		}
 		mx=max(a,max(b,c));
 		mn= min(a,min(b,c));
 		mid=(a+b+c)-mn-mx;
 	}
 	if (ok)cout  << ans1 << " " << ans2 << " " << ans3 << en;
 	else cout << "Impossible\n";
    return 0;
}