#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        int n,k;
        cin >>n>>k;
        string s;
        cin >>s;
        while(k>0){
            int j=1;
            for (int i=1; i<s.size(); i++){
                if (k<=0)break;
                if (s[i-1]=='W' && s[i]=='L' && s[i+j]=='W' && i+j<s.size()){
                    if (j>k){
                        s[i]='W';
                        k--;
                    }
                    else {
                        for (int l=i; l<i+j; l++){
                            k--;
                            s[l]='W';
                        }
                        if (k<=0){
                            i=s.size();
                            break;
                        }
                    }
                }
                else if(s[i]=='L' && s[i-1]=='W' && i){
                    s[i]='W';
                    k--;
                }
                else if (s[i]=='L') {
                    s[i]='W';
                    k--;
                }
            }
            j++;
        }
        int cnt=0;
        for (int i=0; i<s.size(); i++){
            if (i==0 && s[i]=='W')cnt++;
            else if (s[i]=='W' && s[i-1]=='L')cnt++;
            else if (s[i]=='W')cnt+=2;
        }
        cout <<cnt<<endl;
    }   
    return 0;
}