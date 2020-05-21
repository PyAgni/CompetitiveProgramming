#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vec;
typedef std::vector<ld> vecld;
typedef std::vector< std::vector<ll> > vecvec;
typedef std::pair<ll, ll> pr;
typedef std::vector< pr > vpr;

#define tin ll t;cin>>t;while(t--)
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define sz(a) (ll)((a).size())
#define pb push_back
#define trvect(c,i) for(vector<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trset(c,i) for(set<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trmap(c,i) for(map<ll,ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define repp(i,a,b) for(ll i=(a);i<=(b);i++)
#define present(c,x) ((c).find(x) != (c).end())
#define ff first
#define ss second
#define mp make_pair
#define sq(a) (a)*(a)
#define cube(a) (a)*(a)*(a)
#define cnti(x) (__builtin_popcount(x)) //number of set bits in x
#define MOD 1e9+7
#define N 100005

int arr[N],vis[N];
vector<int> adj[N];
int restro;
int M;

void dfs(int node,int m){
	vis[node]++;
	if(arr[node])
		m++;
	else
		m=0;
	if(m>M)
		return;
	if(adj[node].size()==1 && node!=1)
			{	
				// cout<<node<<" ";
				restro++;
			}
	for(auto child : adj[node]){
		if(!vis[child])
			dfs(child,m);
		
	}

	
}

int main(){
    
	int n,m;
	cin>>n>>m;
	repp(i,1,n)
		cin>>arr[i];
	repp(i,1,n-1){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	M=m;
	dfs(1,0);
	cout<<restro;
    
}
