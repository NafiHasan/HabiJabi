#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int s;
    cin >> s;
    vector <char> vc;
    map<char,int>m;
    for (int i=0; i<s; i++){
        char x;
        cin >>x;
        vc.push_back(x);
        m[x]++;
    }
    int n;
    cin >>n;
    vector <int>cnt;
    for (char i='A'; i<='Z'; i++){
        int x=m[i];
        cnt.push_back(x);   
    }
    sort (cnt.rbegin(),cnt.rend());
    int gap=(cnt[0]-1)*n;
    for (int i=1; i<cnt.size(); i++){
        if (cnt[i]!=cnt[0])gap-=cnt[i];
        else if (cnt[i]==cnt[0])gap-=(cnt[i]-1);
    }
    if (gap>=0)cout <<vc.size()+gap<<endl;
    else cout <<vc.size()<<endl;
    return 0;
}