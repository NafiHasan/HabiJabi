#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a=5,b=5;
    int x=++a;  
    int y=b++;
    y=x+b;
    cout <<a<<" "<<b<<" "<<x<<" "<<y<<en; 
    return 0;
}