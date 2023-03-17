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
    
    string s;
    cin >>s;
    int cnt=0;
    int used[s.size()];
    memset (used,0,sizeof(used));
    for (int i=1; i<s.size(); i++){
        if (s[i]=='B' && s[i-1]=='A')cnt=1;
        else if (s[i]=='A' && s[i-1]=='B')cnt=1;
    }
    int got=0;
    for (int i=2; i<s.size(); i++){
        if (s[i]=='A' && s[i-1]=='B' && s[i-2]=='A'){
            got=1;
            used[i]=used[i-1]=used[i-2]=1;
            break;
        }
        if (s[i]=='B' && s[i-1] =='A' && s[i-2]== 'B'){
            got=1;
            used[i]=used[i-1]=used[i-2]=1;
            break;
        }
    }
    if (cnt==0){
        cout <<"NO\n";
        return 0;
    }
    int cnta=0,useda=0,usedb=0,cntb=0;
    for (int i=1; i<s.size()-1; i++){
        if (s[i]=='A' && s[i+1]=='B' && used[i]==0 && used[i+1]==0 && cnta==0){
            cnta=1;
            used[i]=used[i+1]=1;
        }
        else if (s[i]=='A' && s[i-1]=='B' && used[i]==0 && used[i-1]==0 && cntb==0){
            cntb=1;
            used[i]=used[i-1]=1;
        }
        else if (s[i]=='B' &&s[i-1]=='A' && used[i]==0 && used[i-1]==0 && cnta==0){
            cnta=1;
            used[i]=used[i-1]=1;
        }
        else if (s[i]=='B' && s[i+1]=='A' && used[i]==0 && used[i+1]==0 && cntb==0){
            cntb=1;
            used[i]=used[i+1]=1;
        }
    }   
    if (cnta==1 && cntb==1) cout <<"YES\n";
    else if (cnta==1 && got==1)cout <<"YES\n";
    else if (cntb==1 && got==1)cout <<"YES\n";
    else cout <<"NO\n";
    return 0;
}