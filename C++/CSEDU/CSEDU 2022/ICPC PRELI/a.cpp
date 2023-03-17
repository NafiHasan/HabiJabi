#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
	int n;
	cin >> n;
	int ans=1;
	ans+=n/6;
	vector<int>a;
	cout << ans <<en;	
    return 0;
}