#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    int cnt=0;
    string s;
    while (cin >>s){
        cnt=0;
        string s1,s2;
        s1=s.substr(0,6);
        s2=s.substr(6,6);
        if (s1==s2)cout <<"TRUE\n";
        else {
            if (s1[0]==s1[0] && s1[5]==s2[5]){
                if (s1[1]==s2[2] && s1[2]==s2[4] && s1[3]==s2[1] && s1[4]==s2[3])cnt++;
                if (s1[2] == s2[1] && s1[1] == s2[3] && s1[3] == s2[4] && s1[4]==s2[2])cnt++;
                if (s1[1] == s2[4] && s1[2] == s2[3] && s1[3] == s2[2] && s1[4]==s2[1])cnt++;
            }
            if (s1[1]==s2[1] && s1[4]==s2[4]){
                if (s1[0]==s2[2] && s1[2]==s2[5] && s1[3]==s2[0] && s1[5]==s2[3])cnt++;
                if (s1[0] == s2[3] && s1[2] == s2[0] && s1[3] == s2[5] && s1[5] == s2[2])cnt++;
                if (s1[0] == s2[5] && s1[2] == s2[3] && s1[3] == s2[2] && s1[5] == s2[0])cnt++;
            }
            if (s1[2]==s2[2] && s1[3]==s2[3]){
                if (s1[0]==s2[1] && s1[1]==s2[5] && s1[4]==s2[0] && s1[5]==s2[4])cnt++;
                if (s1[0]==s2[4] && s1[1]==s2[0] && s1[4]==s2[5] && s1[5]==s2[1])cnt++;
                if (s1[0]==s2[5] && s1[1]==s2[4] && s1[4]==s2[1] && s1[5]==s2[0])cnt++;
            }
            if (cnt>0) cout <<"TRUE\n";
            else cout <<"FALSE\n";
        }
    }   
    return 0;
}