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
#define mod 1000000007
#define N 100005

ll qpow (ll n, ll m) {
	ll ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % mod;
		n = n * n % mod;
		m >>= 1;
	}
	return ret;
}
ll inv (ll a) {
	return qpow(a, mod - 2);
}


vector<ll> adj[200001];
vector<ll> path;
// bool used[200001],d[200001],p[200001];

ll dist[200001],vis[200001];
void bfs(ll node){
	vis[node]++;
	queue<ll> q;
	q.push(node);

	while(!q.empty()){
		ll curr=q.front();
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

vector<pr> printLevels(vector<ll> graph[], ll V, ll x) 
{     
		ll level[V+1]={0}; 
	    bool marked[V+1]={false}; 
	    vector<pair<ll,ll> > v;
      queue<ll> que; 
      que.push(x); 
      level[x] = 0; 
      marked[x] = true; 
      while (!que.empty()) { 
          x = que.front(); 
          que.pop(); 
  
        for (ll i = 0; i < graph[x].size(); i++) { 
            ll b = graph[x][i]; 
  
            if (!marked[b]) { 
  
                que.push(b); 
  				
                level[b] = level[x] + 1; 
  				if(graph[b].size()==1){
  					v.pb({-1,level[b]});
  				}
  				else
  					v.pb({1,level[b]});
                marked[b] = true; 
            } 
        } 
    } 

    return v;

} 

int main(){
    
	ll n,k;
	cin>>n>>k;
	ll nn=n;
	n-=1;
	while(n--){
		ll a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	// rep(i,1,8){
	// 	rep(j,0,adj[i].size())
	// 		cout<<adj[i][j]<<" ";
	// 	cout<<endl;
	// }

    // bfs(1);

    vpr v = printLevels(adj,nn,1);
    sort(v.begin(),v.end());
    ll ans=0;
    vec vv,temp,temp1;

    rep(i,0,v.size()){
    	if(v[i].ff==1)
    		temp.pb(v[i].ss);
    	else
    		temp1.pb(v[i].ss);
    }
    sort(temp.begin(), temp.end(),greater<int>());
    sort(temp1.begin(), temp1.end(),greater<int>());
    
    int ctr=0;
    rep(i,0,temp1.size())
    	{
    		if(ctr<k){
    		    		ans+=temp1[i];
    		    		ctr++;
    		    	}
    		    	else
    		    		break;
    	}

    k-=ctr;
    // cout<<"k "<<ans;
    if(k>0)
    	rep(i,0,k){
    		ans+=temp[i];
    	}

    cout<<ans<<"\n";
    // rep(i,0,20)
    // 	cout<<dist[i]<<" ";
}
