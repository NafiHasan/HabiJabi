#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	long long n, m , a;
	cin >> n >> m >> a;
	long long a1 = n/a;
	if(n%a != 0)n = a * (a1+1);
	long long a2 = m/a;
	if(m%a != 0)m  = a*(a2+1);
	cout << (n*m)/(a*a) << '\n';	
    return 0;
}