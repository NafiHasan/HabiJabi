#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    priority_queue<int, vector<int>, greater<int>>p;
    p.push(3);   
    p.push(6);
    cout << p.top()<<en;   
    return 0;
}