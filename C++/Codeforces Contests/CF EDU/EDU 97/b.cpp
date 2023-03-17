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
    
    w(t){
        int n;
        cin >>n;
        string s;
        cin >>s;
        int cnt1=0,sum1=0,cnt2=0,sum2=0;
        for (int i=0; i<s.size(); i++){
            if (i && s[i]=='1' && s[i]==s[i-1])cnt1++;
            else if (s[i]=='0'){
                sum1 += cnt1 ;
                cnt1=0;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (i && s[i] == '0' && s[i] == s[i - 1])
                cnt2++;
            else if (s[i] == '1')
            {
                sum2 += cnt2;
                cnt2 = 0;
            }
        }
        cout <<max(sum1,sum2)<<en;
    }
    return 0;
}