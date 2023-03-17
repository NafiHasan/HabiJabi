#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n; cin >>n;
        int ara[n];
        ll odd=0, even=0;
        for (int i=0; i<n; i++){
            cin >> ara[i];
            if (i%2==0)even+=(ll)ara[i];
            else odd+=(ll)ara[i];
        }
        if(odd > even){
            for(int i=0; i<n; i+=2)ara[i]=1;
        }
        else {
            for(int i=1; i<n; i+=2)ara[i]=1;
        }
        for(int i=0; i<n; i++)cout << ara[i]<<" ";
        cout << en;
    }   
    return 0;
}