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
#define endl "\n"
#define deb(x) cerr<< #x << " " << x << endl
#define sz(a) (ll)((a).size())
#define pb emplace_back
#define trvect(c,i) for(vector<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trset(c,i) for(set<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trmap(c,i) for(map<ll,ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define present(c,x) ((c).find(x) != (c).end())
#define all(x) x.begin(), x.end()
#define rall(v) v.rbegin(),v.rend()
#define rsort(v) sort(all(v),greater<int>())
#define mst(x) memset(x, 0, sizeof(x))
#define ff first
#define ss second
#define mp make_pair
#define sq(a) (a)*(a)
#define cube(a) (a)*(a)*(a)
#define cnti(x) (__builtin_popcount(x)) //number of set bits in x
#define N 100005
#define pi 2*acos(0.0)
ll mod = 1e7+7;


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

// ------------------------------------------------------------------------------- //

bool solve(ll *arr,ll n,ll sum){
	ll curr=arr[0],start=0;
	repp(i,1,n){
		while(curr>sum && start<(i-1)){
			curr-=arr[start];
			start++;
		}

		if(curr==sum ){
			if(start==0 && (i-1)>=1 && (start!=(i-1)))
					return 1;
			else if(((i-1)-start)>=1 && start!=(i-1))
				return 1;
			}

		if(i<n)
			curr+=arr[i];
	}
	return 0;
}


int main(){
    
	tin{
		ll n;
		cin>>n;
		ll arr[n];
		rep(i,0,n) cin>>arr[i];

		ll ans=0;
		rep(i,0,n){
			if(solve(arr,n,arr[i])){
				ans++;
				// cout<<arr[i]<<" ";
			}
				}
		// if(solve(arr,n,3))
		// 	cout<<1;
		cout<<ans<<endl;


	}
    
}
