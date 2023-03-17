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
        int n; 
        cin >>n; 
        vector<int>v(n);
        for(int i=0; i<n; i++)cin >>v[i];
        sort(v.begin(), v.end());
        ll num=(ll)v[0]*v[n-1];
        bool ans=true;
        int i=1,j=n-2;
        while(i<=j){
            if ((ll)(v[i] * v[j]) != num)ans=false;
            i++;j--;
        }
        if (ans){
            int cnt=0;
            for(ll i=2; i*i<=num; i++){
                if (num%i==0 && i!=(num/i))cnt+=2;
                else if (num%i==0 && i==num/i)cnt++;
            }
            if (n!=cnt)ans=false;
        }
        if(ans)cout <<num<<en;
        else cout <<"-1\n";
    }    
   return 0;
}