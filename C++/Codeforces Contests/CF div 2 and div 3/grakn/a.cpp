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
        int n;
        cin >>n;
        int ara[n],ara2[n],ara3[n];
        int p[n];
        for (int i=0; i<n; i++){
            cin >>ara[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> ara2[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> ara3[i];
        }
        int crnt=0;
        for (int i=0; i<n; i++){
            //int c=((i+1)%n);
            if (i==0){
                cout << ara[i] << " ";
                crnt=ara[i];
                //p[i]=crnt;
            }
            else if (i==n-1){
                if (ara[0]!=ara2[i] && ara2[i]!=crnt)cout <<ara2[i]<<" ";
                else if (ara[0]!=ara3[i] && ara3[i]!=crnt)cout <<ara3[i]<<" ";
                else if (ara[0]!= ara[i] && ara[i]!=crnt )cout <<ara[i]<<" ";
            }
            else if (ara[i]!=crnt){
                cout << ara[i] << " ";
                crnt=ara[i];
            }
            else if (crnt!=ara2[i] ){
                cout << ara2[i] << " ";
                crnt=ara2[i];
            }
            else if (crnt!=ara3[i] ){
                cout <<ara3[i]<<" ";
                crnt=ara3[i];
            }
        }
        cout <<endl;
    }   
    return 0;
}