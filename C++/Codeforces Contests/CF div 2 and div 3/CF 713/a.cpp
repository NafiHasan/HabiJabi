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
 		int n;
 		cin >> n;
 		int a[n];
 		map<int,int>m;
 		int ind=0;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			m[a[i]]++;
 		}
 		for (int i=0; i<n; i++)if(m[a[i]] == 1)ind = i;
 		cout << ind+1 << en;
 	}	
    return 0;
}