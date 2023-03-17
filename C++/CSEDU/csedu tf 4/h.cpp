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
    
    int cs=1;
    w(t){
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        int start=a*60+b;
        int end=c*60+d;
        cout <<"Case "<<cs++<<": "<<end-start<<en;
    }   
    return 0;
}