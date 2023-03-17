#include <bits/stdc++.h>
using namespace std;
int n, k, w;
int weight[401][401];
int color[401][401];
int vis[11];
int max_c = 11;
vector<pair<int,int>>v;
vector<pair<int,int>>ans;
bool check(int a, int b){
    if(a > n || b > n)return false;
    else return true;
}
int dfs(int a, int b,int wa){
   // cout << a << " " << b << "\n";
    if(a==n && b==n){
        int ca = 0;
        // printf("cas==>");
        for (int i = 1; i < 11; i++)
        {
            if(vis[i] > 0){
                // printf("%d ",i);
                ca++;
            }
        }
        // printf("\n");
        if(wa <= w && ca <= max_c){
            ans.clear();
            max_c = ca;
            // printf("ca-->%d\n",ca);
            for (int i = 0; i < v.size(); i++)
            {
                // printf("%d %d\n",v[i].first,v[i].second);
                ans.push_back(v[i]);
            }
            
        }
    }
    else
    {
        if(check(a+1,b)){
            v.push_back({a+1,b});
            vis[color[a+1][b]]++;
             if(wa+weight[a+1][b] <= w)
                dfs(a+1,b,wa+weight[a+1][b]);
            v.pop_back();
            vis[color[a+1][b]]--;
        }
        if(check(a,b+1)){
            v.push_back({a,b+1});
            vis[color[a][b+1]]++;
             if(wa+weight[a][b+1] <=w)
                dfs(a,b+1,wa+weight[a][b+1]);
            v.pop_back();
            vis[color[a][b+1]]--;
        }
    }
    
}
int main()
{
    scanf("%d %d %d", &n, &k, &w);
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &weight[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &color[i][j]);
        }
    }
    memset(vis,0,sizeof(vis));
    vis[color[1][1]]++;
    dfs(1,1,weight[1][1]);
    
    if(ans.size()==0){
        if(n > 1){
        printf("-1\n");
        }
        else{
            if(weight[1][1] > w){
                printf("-1\n");
            }
            else
            {
                printf("1\n");
                printf("1 1\n");
            }
            
        }
    }
    else
    {
        printf("%d\n",max_c);
        printf("1 1 ");
        for (int i = 0; i < ans.size()-1; i++)
        {
            printf("%d %d ",ans[i].first,ans[i].second);
        }
        printf("%d %d\n",ans[ans.size()-1].first,ans[ans.size()-1].second);
    }
    

}