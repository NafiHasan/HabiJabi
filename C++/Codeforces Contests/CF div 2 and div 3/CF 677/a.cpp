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
    
    w (t){
        string s;
        cin >>s;
        int x=s[0]-'0';
        int len=s.size();
        int c=(x-1)*10+(len*(len+1)/2);
        cout <<c<<endl;
    }
    return 0;
}