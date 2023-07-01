#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

vector<int>v;

int q(int lo, int hi){
    if(lo>=hi)return 0;
    int pos;
    cout << "? " << lo << " " << hi << endl;
    cin >> pos;
    if(hi-lo==1){
        if (pos==lo){
            v.push_back(hi);
            return hi;
        }
        else {
            v.push_back(lo);
            return lo;
        }
    }
    
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,pos;
    cin >> n;
    q(1,n);
    return 0;
}