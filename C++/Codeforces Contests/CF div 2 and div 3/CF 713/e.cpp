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
 		int n,l,r,s;
 		cin >> n >> l >> r >>s;
 		int dif=(r-l+1);
 		int a[dif],sum=0;
 		for (int i=0; i<dif; i++){
 			 a[i] =i+1;
 			 sum+=a[i];
 		}
 		bool ans=1;
 		int last=0, first=(dif*(dif+1))/2;
 		for (int i=n; i>(n-dif); i--)last+=i;
 		if(s <first || s > last )ans=0;
 		for (int i=dif-1; i>=0; i--){
 			if(s==sum)break;
 			if(i==dif-1){
 				int add=n-a[i];
 				if(sum+add > s){
 					a[i]+=s-sum;
 					break;
 				}
 				else {
 					a[i]=n;
 					sum+=add;
 				}
 			}
 			else {
 				int add=(a[i+1]-1)-a[i];
 				if(sum+add > s){
 					a[i]+=s-sum;
 					break;
 				}
 				else {
 					a[i]=a[i+1]-1;
 					sum+=add;
 				}
 			}
 		}
 		if(ans){
 			set<int>m;
 			for (int i=1; i<=n; i++)m.insert(i);
 			int fin[n];
 			for(int i=0,j=l-1; i<dif; j++,i++){
 				fin[j]=a[i];
 				m.erase(a[i]);
 			}
 			for(int i=0 ;i<n; i++){
 				if(i>=l-1 && i<=r-1)continue;
 				int z=*m.begin();
 				fin[i]=z;
 				m.erase(z);
 			}
 			for (int i=0; i<n; i++)cout << fin[i] << " ";
 			cout << en;
 		}
 		else cout << "-1\n";
 	}	
    return 0;
}