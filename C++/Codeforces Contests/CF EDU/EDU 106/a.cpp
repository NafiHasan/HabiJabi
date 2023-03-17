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
 		int n, k1, k2;
 		cin >> n >> k1 >> k2;
 		int w,b;
 		cin >>w >> b;
 		w*=2, b*=2;
 		int white=k1+k2;
 		int black=(2*n)-white;
 		if (w<=white && b <= black)cout << "YES\n";
 		else cout << "NO\n";
 	}
    return 0;
}