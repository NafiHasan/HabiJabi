#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int n, q;
 	cin >> n >> q;
 	vector<int>ind(55,n+1);
 	for (int i=0; i<n; i++){
 		int a;
 		cin>> a;
 		ind[a]=min(ind[a],i+1);
 	}	
 	while(q--){
 		int a;
 		cin >> a;
 		cout << ind[a] << " ";
 		for (int i=1; i<51; i++){
 			if(ind[i] < ind[a])ind[i]++;
 		}
 		ind[a]=1;
 	}
 	cout << en;
    return 0;
}