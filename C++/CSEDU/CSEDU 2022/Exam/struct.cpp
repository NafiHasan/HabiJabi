#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct duo{
	int a, b;
	// char s1[30], s2[25];
};

// typedef struct duo dd;
// struct duo doub(){
// 	duo d1;
// 	d1.a = 50;
// 	d1.b= 4;
// 	return d1;
// }

int main()
{
	fast_io();
 	// duo a = doub();
 	// cout << a.a << '\n';
 	cout << sizeof(duo) << '\n';	
    return 0;
}