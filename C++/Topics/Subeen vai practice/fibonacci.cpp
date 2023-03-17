#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

int f_calls =0;

int fib(int n){
    f_calls++;
    if (n==1 || n==2) return 1;
    return fib(n-1)+fib(n-2);
}

int main ()
{
    int n;
    cin>>n;
    cout << "nth fibo= "<<fib(n)<< endl;
    cout << "function calls= "<<f_calls<<endl;
    return 0;
}