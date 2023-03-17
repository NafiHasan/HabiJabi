#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int n, h;
 	cin >> n >> h;
 	int a[n];
 	int ans =0;
 	for (int i=0; i<n; i++){
 		cin >> a[i];
 		if(a[i] > h)ans++;
 		ans++;
 	}	
 	cout<< ans << '\n';
    return 0;
}