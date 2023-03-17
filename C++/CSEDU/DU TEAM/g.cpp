#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n,m;
        cin >>n>>m;
        int ara[m];
        for (int i=0; i<m; i++)cin >>ara[i];
        int notes[]={1,5,10,20,50};
        int cnt[5]={0,0,0,0,0};
        for(int i=0; i<m; i++){
            while(ara[i]>0){
                for (int j = 4; j >= 0; j--){
                    if (ara[i] >notes[j] && cnt[j]==0){
                        int x=ara[i]%notes[j];
                        ara[i]-=notes[j];
                        cnt[j]++;
                    }
                }
            }
        }
        int sum=notes[0]*1+notes[1]*5+notes[2]*10+notes[3]*20+notes[4]*50;
        int gap=n-sum;
        while(gap>0){
            for (int i=4; i>=0; i--){
                int x=gap/notes[i];
                gap-=x*notes[i];
                cnt[i]+=x;
            }
        }
        for(int i=0; i<5; i++)cout <<cnt[i]<<" ";
        cout <<en;
    }   
    return 0;
}