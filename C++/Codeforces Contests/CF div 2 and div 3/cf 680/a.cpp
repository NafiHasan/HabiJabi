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
        int n,x;
        string blank;
        scanf("%d %d",&n,&x);
        int ara1[n],ara2[n];
        for (int i=0; i<n; i++)cin >>ara1[i];
        for (int i=0; i<n; i++)cin >>ara2[i];
        getline(cin,blank);
        int cnt=0;
        sort (ara1,ara1+n);
        sort (ara2,ara2+n,greater<int>());
        for (int i=0; i<n; i++){
            if (ara1[i]+ara2[i]>x){
                cout <<"NO\n";
                cnt=1;
                break;
            }
        }
        if (cnt==0)cout <<"YES\n";
    }
    return 0;
}