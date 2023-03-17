#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

bool base(int n, int b){
    string s;
    while(n>0){
        int rem=n%b;
        //if (b==13)cout<<rem<<" ";
        if (rem<=9)s+=(rem+'0');
        else s+=(rem+55);
        n/=b;
    }
    //if (b==13)cout <<s<<en;
    string s2=s;
    reverse(s.begin(), s.end());
    if (s==s2)return true;
    else return false;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >> n;
        bool ans=false;
        vector <int>v;
        for (int i=2; i<=16; i++){
            if (base(n,i)){
                ans=true;
                v.push_back(i);
            }
        }
        sort (v.begin(), v.end());
        if (ans){
            for (int i=0; i<v.size(); i++)cout <<v[i]<<" ";
            cout <<en;
        }
        else cout <<"-1\n";
    }
    
    return 0;
}