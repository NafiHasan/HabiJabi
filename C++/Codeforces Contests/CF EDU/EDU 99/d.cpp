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
        int n,x;
        cin >>n>>x;
        int ara[n],tmp[n];
        int cnt=0,last=0;
        bool ans=true,sorted=true;
        for (int i=0;i <n; i++){
            cin >> ara[i];
            if (i && ara[i]<ara[i-1]){
                sorted = false;
                last=i;
            }
        }
        if (!sorted){
            for (int i = 0; i < n-1; i++)
            {
                if (ara[i] >x && i<last)
                {
                    swap(ara[i],x);
                    cnt++;
                }
            }
        }
        for (int i=0; i<n; i++){
            if (i && ara[i]<ara[i-1])ans=false;
        }
        if (ans)cout <<cnt<<en;
        else cout <<"-1\n";
    }   
    return 0;
}