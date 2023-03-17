#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

bool found(string s, int lo, int hi, char c){
    int mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if (s[mid]==c)return true;
        else if (s[mid]<c)lo=mid+1;
        else hi=mid-1;
    }
    return false;
}

int main ()
{
    map<int,int>m;
    m[3]++;
    cout <<m.size()<<endl;
    m[3]--;
    if (m[3]==0)m[3]=-1;
    cout <<m.size()<<endl;
      
}