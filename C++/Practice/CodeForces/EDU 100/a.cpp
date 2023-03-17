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
        int a,b,c;
        cin >> a>>b>>c;
        int sum=a+b+c,  mn=min({a,b,c});
        if(sum>=9 && sum%9 == 0 && (sum/9)<=mn)cout <<"yes\n";
        else cout <<"no\n";
    }   
    return 0;
}