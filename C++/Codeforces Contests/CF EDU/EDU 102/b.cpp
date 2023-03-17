#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

bool div(string s, string com){
    if (s==com)return true;
    else {
        string a=s;
        while(s.size()<=com.size()){
            if (s==com)return true;
            else s+=a;
        }
    }
    return false;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        string s1,s2;
        cin >>s1>>s2;
        if (s1.size()>s2.size())swap(s1,s2);
        string need=s1;
        bool ans=false;
        while(need.size() <= s1.size()*s2.size()){
            if (div(s1,need) && div(s2,need)){
                ans=true;
                break;
            }
            else need+=s1;
        }
        if (ans)cout <<need<<en;
        else cout <<"-1\n";
    }   
    return 0;
}