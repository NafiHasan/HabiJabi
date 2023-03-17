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
    string s;
    cin>>s;
    int f=0,o=0,cnt=0;
    for (int i=0; i<n; i++){
        if (s[i]=='f')f++;
        else if (s[i]=='o' && f>0 && i!=n-1 && s[i+1]=='x'){
            f--;
            cnt += 3;
            i++;
            //cout <<i<<" ";
        }
        else if (s[i]=='o' && f>0 && s[i+1]=='f' && i!=n-1)o++;
        else if (s[i]=='x' && f>0 && o>0){
            f--;o--;cnt+=3;
        }
        else {
            f=0;o=0;
            //cout <<i<<" ";
        }
    }
    cout <<n-cnt<<en;
    return 0;
}