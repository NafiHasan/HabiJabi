#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int p,d,m,s;
    cin >>p>>d>>m>>s;
    int cnt=0;
    while(p>0){
        if (s-p>=0){
            s-=p;
            cnt++;
            //cout <<p<<en;
        }
        else break;
        if (p-d>=m){
            p-=d;
        }
        else p=m;
    }
    cout <<cnt<<en;
    return 0;
}