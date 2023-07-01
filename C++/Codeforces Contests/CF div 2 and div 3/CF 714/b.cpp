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
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
		int left=1 ;
	for (int i=0; i<n-1; i++){
		if(i==0)left = a[i];
		else left &= a[i];
		int right=1;
		for (int j=i+1; j<n; j++){
			if(j==i+1)right = a[j];
			else right &= a[j];
		}
		if(left != right){
			for (int j=0; j<=i; j++)cout << a[j] <<" ";
			cout << en;
			for(int j=i+1; j<n; j++) cout << a[j] << " ";
			cout << en;
		}
	}	
    return 0;
}