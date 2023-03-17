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
        int n;
        cin >> n;
        int ara[n];
        for(int i=0; i<n; i++)cin >>ara[i];
        int room[n],ans=true;
        memset(room, false, sizeof(room));
        for(int i=0; i<n; i++){
            int x=i%n;
            if (x<0)x+=n;
            ll rm=(ll)(i+ara[x]);
            int r=rm%(ll)n;
            if (r<0)r+=n;
            room[i]=r;
            //cout <<r<<en;
            //cout <<rm<<en;
        }
        sort (room,room+n);
        for (int i=0; i<n; i++){
            if (room[i]!=i){
                ans=false;
                //cout <<room[i]<<" "<<i<<en;
                break;
            }
        }
        if(ans)cout <<"yes\n";
        else cout << "no\n";
    }   
    return 0;
}