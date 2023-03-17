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
    
    w(t){
        string s;
        cin >>s;
        int cnt=0;
        if (s[0]!=s[s.size()-1])cnt++;
        for (int i=0; i<s.size(); i++){
            if (i && s[i]!=s[i-1])cnt++;
        }
        if (cnt<=2)cout <<"uniform\n";
        else
            cout << "non-uniform\n";
    }   
    return 0;
}