#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int cnt =0;

void merge(vector<int>a, int lo , int hi){
	cnt++;
	// cout << lo << ' ' << hi << '\n';
	if(cnt > 10)return;
	bool cl =0;
	if(hi - lo == 0)return;
	for (int i=lo; i< hi; i++){
		if(i > lo  && a[i] < a[i-1]){
			cl = 1;
			// cout << lo << ' ' << hi-1 << "\n";
			break;
		}
	}
	if(cl){
		int loo = lo, hii = hi; 
		int mid = (loo+hii)/2;
		merge(a, loo, mid);
		merge(a, mid, hii);
	}
}



int main()
{
	fast_io();
 	int n;
 	cin >> n;
 	vector<int>a(n);
 	for (int i=0; i<n; i++)cin>> a[i];
 	merge(a, 0, a.size());
 	cout << cnt << '\n';
    return 0;
}