#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int n, q;
 	cin >> n;
 	vector<int>a(n);
 	for (int i=0; i<n; i++)cin>> a[i];	
 	cin >> q;
 	while(q--){
 		int x;
 		cin>> x;
 		int lo = 0, hi = n-1, mid, srt = -1;
 		while(lo <= hi){
 			mid = (lo + hi)/2;
 			if(a[mid] >= x)hi = mid - 1;
 			else {
 				srt = a[mid];
 				lo = mid + 1;
 			}
 		}
 		if(srt == -1)cout << "X ";
 		else cout << srt << ' ';
 		lo = 0, hi = n-1;
 		srt = -1;
 		while(lo <= hi){
 			mid = (lo + hi)/2;
 			if(a[mid] <= x) lo = mid + 1;
 			else {
 				srt = a[mid];
 				hi = mid-1;
 			}
 		}
 		if(srt == -1) cout<< "X\n";
 		else cout << srt << '\n';
 	}
    return 0;
}