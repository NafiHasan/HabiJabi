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
    
    string s,s2;
    cin >>s;
    s2=s;
    reverse(s2.begin(),s2.end());
    if (s==s2){
        cout <<"0\n";
        return 0;
    }
    int len=s.size();
    cout <<"3\n";
    cout <<"R "<<len-1<<endl;
    cout <<"L "<<len<<endl<<"L 2\n";
    return 0;
}