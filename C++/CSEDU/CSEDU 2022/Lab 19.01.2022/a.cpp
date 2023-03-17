#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long sum(int i, long long a[], int n){
	if(i >= n)return 0;
	return a[i] + sum(i+1, a, n);
}


int main()
{
	fast_io();
 	int n;
 	cin >> n ;
 	cin>>n;
 	long long a[n];
 	for (int i=0; i<n; i++)cin >> a[i];
 	cout << sum(0, a, n) << '\n'; 	
    return 0;
}