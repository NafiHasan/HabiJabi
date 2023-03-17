#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    vector <int>v={1,2,3,4,5};
    v.erase(v.begin()+0);
    for (auto it = v.begin(); it != v.end(); ++it) 
        cout << *it;
    cout <<endl;
    v.pop_back();
    for (auto it = v.begin(); it != v.end(); ++it) 
        cout << *it;
    cout <<endl;
    return 0;
}