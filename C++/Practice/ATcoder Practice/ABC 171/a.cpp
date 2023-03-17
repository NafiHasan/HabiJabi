#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	char c;
 	cin >> c;
 	if (c<96)cout << "A\n";
 	else cout << "a\n";
    return 0;
}