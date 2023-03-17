#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a[6],sum=0;
    for(int i=0; i<6; i++){
        cin >> a[i];
        sum+=a[i];
    }
    int ans=0;
    bool found= false;
    while(sum>=3){
        if(found){
            int mx=*max_element(a,a+6), ind=0;
            for(int i=0; i<6; i++){
                if (a[i] == mx){
                    ind =i;
                    break;
                }
            }
            int ind2=(ind+3)%6;
            while(a[ind]>a[ind2]){
                ans+=2*a[ind]-1;
                a[ind]--;
            }
            break;
        }
        if(!found){
            for (int i = 0; i < 6; i++)
            {
                ans += a[i] * 2 - 1;
                a[i]--;
                if (a[i] == 0)
                    found = true;
            }
            sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
        }
    }   
    cout << ans<< "\n";
    return 0;
}