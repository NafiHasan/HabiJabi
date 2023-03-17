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
        int ara[n+1];
        ara[0]=0;
        map<int,int>occu;
        map<int,int>cnted;
        for (int i=1; i<=n; i++){
            cin >> ara[i];
            cnted[ara[i]]++;
            if (occu[ara[i]]==0){
                occu[ara[i]]++;
                cnted[ara[i]]--;
            }
        }
        sort (ara,ara+n+1);
        int oc=0,sum=0;
        for (int i=1; i<=n; i++){
            if (cnted[ara[i]]>0){
                for (int j=1; ;j++){
                    if (occu[ara[i]-j]==0 && (ara[i]-j)>0){
                        sum+=j;
                        occu[ara[i]-j]=1;
                        break;
                    }
                    else if (occu[ara[i]+j]==0){
                        sum+=j;
                        occu[ara[i]+j]=1;
                        break;
                    }
                }
                cout<<ara[i]<<" "<<sum<<en;
                cnted[ara[i]]--;
            }
        }
        cout <<sum<<en;
    }   
    return 0;
}