#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void do_sort(int* a, int ind, int sz){
	if(ind <= sz/2){
		return;
	}
	int tmp = a[sz - ind];
	a[sz - ind] = a[ind-1];
	a[ind-1] = tmp;
	do_sort( a, ind-1, sz);
}


int main()
{
	fast_io();
 	int n;
 	cin >> n;
 	int a[n];
 	for (int i=0; i<n; i++)cin>> a[i];
 	do_sort(a, n, n);
 	for (int i=0; i<n; i++)cout << a[i] << ' ';
    return 0;
}