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
    
    w(t){
        int n;
        cin >>n;
        int ara[n];
        ll sum=0;
        for (int i=0; i<n; i++){
            cin >>ara[i];
            sum+=(ll)ara[i];
        }
        vector<char>ch(n+1);
        ll des=(ll)n*(ll)(n+1)/(ll)2;
        if (des==sum)ch[1]='1';
        else ch[1]='0';
        for (int i=1; i<n; i++){
            sum=0;
            for (int j=0; j<n; j+=i){
                sum+=ara[j];
            }
            des=(ll)(n-i)*(n-i+1)/2;
            if (sum==des)ch[i+1]='1';
            else ch[i+1]='0';
        }
        for (int i=1; i<=n; i++)cout <<ch[i];
        cout <<en;
    }   
    return 0;
}