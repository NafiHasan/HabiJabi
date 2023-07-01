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
    
    int n;
    cin >>n;
    int m=2*n;
    deque<int >d;
    char prev;
    int prenum,cnt=0;
    for (int i=1; i<=m; i++){
        string s;
        cin >>s;                                              
        int val;
        if (s[0]=='-')cin >>val;
        if (i==1 && s[0]=='-'){
            cout <<"NO\n";
            return 0;
        }
        if (cnt<0){
            cout <<"NO\n";
            return 0;
        }
        if (i>1 && s[0]==prev && s[0]=='-' && val<prenum){
            cout <<"NO\n";
            return 0;
        }
        if (s[0]=='+')cnt++;
        else if (s[0]=='-')cnt--;
        if (s[0]=='-'){
            prenum=val;
            d.push_back(val);
        }
        prev=s[0];
        if (i==m && s[0]=='-')d.push_front(val);
        else if (i==m && s[0]=='+'){
            cout <<"NO\n";
            return 0;
        }
    }
    cout <<"YES\n";
    for (int i=0; i<n; i++){
        cout <<d[i]<<" ";
    }
    cout <<en;
    return 0;
}