#include<bits/stdc++.h>
using namespace std;

#define dvg(x) cout<<#x<<" = "<<x<<endl;
#define dvg2(x, y) cout<<#x<<" = "<<x<<" " <<#y<<" = "<<y<<endl;
#define endl "\n"
#define ll long long
#define l64 int64_t
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define pp() pop_back()
#define in(x) insert(x)
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define pn(n) cout<<n<<"\n";
#define pr(ar) {for (auto i : ar) cout<<i<<" "; cout<<"\n";}
#define cn(v) for(auto &i : v) cin>>i;
#define sq(a) ((a)*(a))

int dx[] {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

ll const mod = 1e9 + 7;
int const N = 1e5 + 10;

void solve()
{
  int n; cin>>n;

  vi v(n);
  cn(v);
  string s; cin>>s;

  vi red, blue;

  for(int i = 0; i < n; i++)
  {
    if(s[i] == 'B') blue.pb(v[i]);
    else red.pb(v[i]);
  }
  sort(red.begin(), red.end(), greater<int>());
  sort(blue.begin(), blue.end(), greater<int>());
 // pr(blue);
  //pr(red);
  for(int i = 1; i <= n; i++)
  {
    if(blue.size() > 0 && blue.back() >= i){
      blue.pp();
      //dvg(i);
    }
    else if(red.size() > 0 && red.back() <= i)
    {
      red.pp();
      //dvg(i);
    }
  }
  if(red.size() + blue.size() == 0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T = 1;
   cin>>T;
  while(T--)
  {  
    solve();
  }

  return 0;
}
