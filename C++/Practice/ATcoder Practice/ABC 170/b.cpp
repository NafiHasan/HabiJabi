#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	int x, y;
 	cin >> x >> y;
 	int lo = x*2, hi=x*4;
 	//cout << avg<<en;
 	if (y >= lo && y <= hi && y%2==0)cout <<"Yes\n";
 	else cout << "No\n";	
    return 0;
}