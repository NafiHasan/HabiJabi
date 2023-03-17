#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

void found(string s, int lo, int hi, char c){
    int mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if (s[mid]==c){
            cout <<"found\n";
            break;
        }
        else if (s[mid]<c)lo=mid+1;
        else hi=mid-1;
    }
    cout <<"not found\n";
}

int main ()
{
    string s="bce";
    sort(s.begin(),s.end());
    found(s,0,s.size()-1,'a');
    return 0;
}