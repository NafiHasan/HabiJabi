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
    	cin >> n >> k;
    	if(k*2+1 <=n){
    		int  a[n];
    		memset(a,0,sizeof(a));
    		a[0]=1;
    		int has=2;
    		int last=n;
    		for (int i=1; i<n; i+=2){
    			if(k>0){
    				a[i]=last--;
    				k--;
    			}
    		}
    		for (int i=0; i<n; i++){
    			if(a[i]==0)a[i]=has++;
    		}
    		for (int i=0 ;i<n; i++)cout << a[i] << " ";
    		cout << en;
    	}
    	else cout << "-1\n";
    }
    return 0;
}