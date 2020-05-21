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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define present(c,x) ((c).find(x) != (c).end())
#define ff first
#define ss second
#define mp make_pair
#define sq(a) (a)*(a)
#define cube(a) (a)*(a)*(a)
#define cnti(x) (__builtin_popcount(x)) //number of set bits in x
#define MOD 1e9+7
#define N 100005

int ans;
vector<int> adj[10001];
int dist[10001],vis[10001];

void buildGraph(int n,int m){
	for(int i=n;i<=2*m;i++){
		for(int j=0;j<=2*m;j++){
			if(j==i-1 || j==2*i)
				adj[i].pb(j),adj[j].pb(i);
		}
	}
}

void bfs(int node){
	vis[node]++;
	queue<int> q;
	q.push(node);

	while(!q.empty()){
		int curr=q.front();
		q.pop();

		for(auto child: adj[node]){
			if(!vis[child]){
				vis[child]++;
				dist[child]=dist[curr]+1;
				q.push(child);
			}
		}
	}
}

int main(){
    
	int n,m;
	cin>>n>>m;
	
	buildGraph(n,m);
	bfs(n);
	// rep(i,0,50)
	rep(i,0,100)
	cout<<adj[i].size()<<" ";

	// rep(i,1,100)
	// 	cout<<dist[i]<<" ";






// Alternate sol. w/o dfs
	// while(1){
	// 	if(n==m) break;

	// 	if(m%2==0 && (n<m)){
	// 		ans++;
	// 		m/=2;
	// 	}
	// 	else{
	// 		ans++;
	// 		m++;
	// 	}
	// }
	// dfs(n,m);
	cout<<ans;
    
}
