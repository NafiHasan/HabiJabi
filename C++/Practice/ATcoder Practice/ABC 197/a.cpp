#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
    string s;
    cin >> s;
    char tmp=s[0];
    s[0]=s[1];
    s[1]=s[2];
    s[2]=tmp;
    cout << s <<en; 		
    return 0;
}