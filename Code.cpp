#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define endl "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define INF 2e18
#define all(v) (v).begin(), (v).end()
//is_sorted(all(v))
/*auto ip =unique(s.begin(),s.end());
  s.resize(distance(s.begin(), ip));*/
//int mx = *max_element(a.begin(), a.end());
//int cmx = count(a.begin(), a.end(), mx);
//(y<<x)->y*2^x
//(y>>x)->y/2^x
//sort(m[i].begin(),m[i].end(),greater<ll>());
//s.erase(start,start+nth)
//((f*=i)%=M);
// string x=s.substr(st,en+1);
// int cnt= count(st, en+1, c);
/*ll fact[200005];
ll pw(ll a,ll b){
	ll ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans =ans* a;
			ans=ans% M;
		}
		b =b/ 2;
		a =a * a;
		a =a % M;
	}
	return ans;
}
ll inv(ll z){
	return pw(z, M-2);
}*/
int parent[10];
int rank1[10];
void fun()
{
    for(int i=0;i<10;i++)
    parent[i]=i;

    for(int i=0;i<10;i++)
    rank1[i]=0;
}
int findparent(int u)
{
    if(u==parent[u])
        return u;

        return parent[u]=findparent(parent[u]);
}
void union1(int u,int v)
{
    u=findparent(u);
    v=findparent(v);
    if(rank1[u]<rank1[v])
    {
        parent[u]=v;
    }
    else if(rank1[v]<rank1[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank1[u]++;
    }
}
void solve()
{
    fun();
   int m;
   cin>>m;
   int u,v;
   forn(i,m)
   {
       cin>>u>>v;
       union1(u,v);
   }
   int a,b;
   int n;
   cin>>n;
   while(n--){
   cin>>a>>b;
   if(findparent(a)==findparent(b))
    cout<<"They Belongs To Same Component"<<endl;
   else
    cout<<"They Does Not Belongs To Same Component"<<endl;}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
