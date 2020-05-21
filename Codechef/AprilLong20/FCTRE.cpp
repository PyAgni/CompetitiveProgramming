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

std::vector<ll> adj[1001];
ll vis[1001],p[1001];


void bfs(ll node){
	vis[node]++;
	queue<ll> q;
	q.push(node);
	p[node]=-1;
	while(!q.empty()){
		ll curr = q.front();
		q.pop();

		for(auto child : adj[curr]){
			if(!vis[child]){
				vis[child]++;
				q.push(child);
				p[child]=curr;
			}
		}
	}
}



vec printPath(ll u,ll v){
	// if(!vis[u] || !vis[v]){
	// 	cout<<-1;
	// }
	// else
	vec shortestPath;
	{
		vec path;
		// ll temp=v;
		// while(p[temp]!=-1){

		// }
		for(ll i=u;i!=-1;i=p[i])
			path.pb(i);

		reverse(path.begin(), path.end());
		for(ll i : path)
			{	
				// cout<<i<<" ";
				shortestPath.pb(i);}
	}
	return shortestPath;
}

// ref - https://www.geeksforgeeks.org/count-divisors-array-multiplication/

void sieve(ll largest, vector<ll> &prime) 
{ 
 
	bool isPrime[largest+1]; 
	memset(isPrime, true, sizeof(isPrime)); 

	for (ll p=2; p*p<=largest; p++) 
	{ 
		if (isPrime[p] == true) 
		{ 
			for (ll i=p*2; i<=largest; i += p) 
				isPrime[i] = false; 
		} 
	} 

	for (ll p=2; p<=largest; p++) 
		if (isPrime[p]) 
			prime.push_back(p); 
} 


ll count(vector<ll> arr) 
{ 
	ll n = arr.size();
	ll largest = *max_element(arr.begin(), arr.end()); 
	vector<ll> prime; 
	sieve(largest, prime); 

	unordered_map<ll, ll> mp; 
	for (ll i=0; i<n; i++) 
	{ 
		for (ll j=0; j<prime.size(); j++) 
		{ 
			while(arr[i] > 1 && arr[i]%prime[j] ==0 ) 
			{ 
				arr[i] /= prime[j]; 
				mp[prime[j]]++; 
			} 
		} 
		if (arr[i] != 1) 
			mp[arr[i]]++; 
	} 
 
	ll res = 1; 
	for (auto it : mp) 
	res *= (it.second + 1L); 

	return res; 
} 


int main(){
    // generatePF();
	tin{
		ll n,m;
		cin>>n;
		m=n-1;
		while(m--){
			ll a,b;
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		ll cost[n];
		rep(i,0,n) cin>>cost[i];
		ll q;
		cin>>q;

		bfs(1);
		while(q--){
			ll u,v;
			cin>>u>>v;
			if(u==v){
				vec v;
				v.pb(cost[u-1]);
				cout<<count(v)%(1000000007)<<endl;
				continue;
			}
			vec sPath = printPath(v,u);
			ll ans=1;
			vector<ll> result;
			for(ll i=0;i<sPath.size();i++){
				// ans=(ans*cost[sPath[i]-1])%(1000000007);
				// cout<<cost[shortestPath[i]-1]<<" ";
				result.pb(cost[sPath[i]-1]);
			}
			// cout<<ans<<" ";
			cout<<count(result)%(1000000007)<<endl;
		}
		
	}
    
}
