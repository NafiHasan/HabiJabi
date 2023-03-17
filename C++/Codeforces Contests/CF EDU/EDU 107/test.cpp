#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	cout << 50 << " " << 300000 <<en;
 	for (int i=0; i<50 ; i++) {
 		if(i)cout << " ";
 		cout << i+1 ;
 	}
 	cout << en;
 	int a=50;
 	for (int i=0; i<300000; i++){
 		if(i)cout << " ";
 		cout << a ;
 	}	
 	cout << en;
    return 0;
}