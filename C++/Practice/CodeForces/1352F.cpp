#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        if (c>0)for (int i=0; i<=c; i++)s+='1';
        if (a>0)for(int i=0; i<=a; i++)s+='0';
        int prev=1;
        if (b>0 && c==0)s+='1';
        if (a==0 && b>0){
            s += '0';
            b--;
        }
        if (a > 0)
            b--;
        while(b>0){
            if (prev==1) {
                s += '0';
                prev=0;
            }
            else {
                s+='1';
                prev=1;
            } 
            b--;
        }
        cout <<s<<en;
    }   
    return 0;
}