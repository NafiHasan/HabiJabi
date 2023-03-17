#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int>arr[26];
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i]-97].push_back(i);
    }
    int n, q;
    scanf("%d %d", &n, &q);
    vector<string>words(n);
    int count[n][26];
    memset(count,0,sizeof(count));
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        // printf("sfasjdfh\n");
    }
    sort(words.begin(),words.end());
    // printf("hjsgf\n");
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < words[i].size(); j++){
            count[i][words[i][j]-97]++;
            // printf("lasjdkfas\n");
        }
    }
    // printf("hjsgf2\n");
    // vector<pair<pair<int,int>,int>>queries;
    for(int j = 0 ; j < q; j++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        vector<int>v(26);
        for (int i = 0; i < 26; i++)
        {
            if(arr[i].size()==0){
                
                v[i] = 0;
                continue;
            }
            int idx1 = lower_bound(arr[i].begin(),arr[i].end(),l-1)-arr[i].begin();
            int idx2 = lower_bound(arr[i].begin(),arr[i].end(),r-1)-arr[i].begin();
            if(arr[i][idx2]== r-1)idx2++;
            v[i] = idx2-idx1;
        }
        int p = 0;
        string ans;
        //pri??ntf("FGHJ\n");
        // printf("%d %d %d %d %d %d\n",v[9],v[10],v[11],count[2][9],count[2][10],count[2][11]);
        for (int i = 0; i < n; i++)
        {
            bool ok = true;
            for(int l = 0; l < 26; l++){
                if(count[i][l] > v[l]){
                    ok = false;
                }
            }
            if(ok){
                // cout << words[i] <<endl;
                p++;
                if(p==k){
                    ans = words[i];
                }
            }
        }
        if(p < k){
            printf("NO SUCH WORD\n");
        }
        else
        {
            int t = ans.size();
            for (int i = 0; i < min(t,11); i++)
            {
                printf("%c",ans[i]);
            }
            printf("\n");
        }
        
    }
}