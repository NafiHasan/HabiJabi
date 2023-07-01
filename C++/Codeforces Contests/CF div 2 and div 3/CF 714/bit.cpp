#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	for (int i=1; i<20; i++){
 		for (int j=1; j<20; j++){
 			if((i&j) == i)cout << i << " " << j <<en;
 		}
 	}	
    return 0;
}