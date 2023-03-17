#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	long long a ,b;
 	cin >> a >>b;
 	cout << (long long)pow(32LL, a-b) << "\n";	
    return 0;
}