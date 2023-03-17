#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t;
    cin>>t ;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n]; 
        int b[n];    // times of alice and bob

        for(int i = 0 ; i<n ; i++)
        {
            cin>>a[i];   //alice times
        }
        for(int i = 0 ; i<n ; i++)
        {
            cin>>b[i];    //bob times
        }

        int am = 0 , bm = 0 ;    // index for the maximum times for alice and bob

        for(int i = 1 ; i<n ; i++)
        {
            if(a[i]>=a[am])
            {
                am = i;       // a[am] is maximum time
            }
        }
        cout << am + 1 << '\n';
        for(int i = 1 ; i<n ; i++)
        {
            if(b[i]>=b[bm])
            {
                bm = i;       // b[bm] is the maximum time 
            }
        }

        int at = 0 , bt = 0 ;   // at and bt are total time fot alice and bob 

        for(int i = 0 ; i<n ; i++)
        {
            at = at + a[i];
        }
        for(int i = 0 ; i<n ; i++)
        {
            bt = bt + b[i];
        }

        at = at - a[am];   // total time  - max time for alice
        bt = bt - b[bm];    // total time - max time for bob

        if(at == bt)
        {
            cout<<"Draw"<<endl;
        }
        else if(at>bt)
        {
            cout<<"Bob"<<endl;
        }
        else if(bt>at)
        {
            cout<<"Alice"<<endl;
        }

    }
}