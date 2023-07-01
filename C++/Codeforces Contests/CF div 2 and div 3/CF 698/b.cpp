#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

bool com(int n, int d){
    string s=to_string(n);
    char c=d+'0';
    for (int i=0; i<s.size(); i++){
        if (s[i]==c)return true;
    }
    return false;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int q,d;
        cin >>q>>d;
        int a[q];
        for (int i=0; i<q; i++)cin >>a[i];
        for (int i=0; i<q; i++){
            int num=a[i];
            int have=num/d, mo=num%d;
            bool found=false;
            if (com(num,d))found=true;
            int it=1;
            while(have-- && it<=12 && mo+d <= a[i]){
                it++;
                mo+=d;
                //cout <<num<<" ";
                if (com(mo,d)){
                    found =true;
                    break;
                }
            }
            if (found)cout <<"YES\n";
            else cout <<"NO\n";
        }
    }   
    return 0;
}