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
const int mod = 1000000007;

// --------------------------- Inputs ---------------------------------------------- //

template<typename... T>
void read(T&... args){
	((cin>>args), ...);
}

template <typename T , typename T0>
void read(pair< T , T0 > &p){
	cin >> p.ff >>p.ss;
}

template <typename T>
void read(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}

template <typename T>
void read(T oneD[] , int n){
	for(ll i=0;i<n;i++){
		read(oneD[i]);
	}
}

// --------------------------- Outputs --------------------------------------------- //

template<typename... T>
void write(T... args){
	((cout<<args<<" "), ...);
	cout<<endl;
}

template <typename T , typename T0>
void write(pair< T , T0 > &p){
	write(p.ff);
	write(p.ss);
	cout << endl;
}

template <typename T>
void write(vector< T > &oneD){
  for(ll i=0;i<oneD.size();i++){
    cout<<oneD[i]<<" ";
  }
  cout<<endl;
}

template <typename T ,typename T0>
void write(vector< pair< T, T0 > > &oneD){
  for(ll i=0;i<oneD.size();i++){
    write(oneD[i].ff,oneD[i].ss);
  }
} 

template <typename T>
void write(T oneD[] ,int n){
	for(ll i=0;i<n;i++){
		cout<<oneD[i]<<" ";
	}
	cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp){
	for(auto it : mpp){
		write(it.ff);
		cout << ": ";
		write(it.ss);
		cout << "\n";
	}
	cout<<endl;
}
// -------------------------------------------------------------------------------- //



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

ll** solve(ll *arr,ll n,ll sum){
	// ll dp[n+1][sum+1];
	ll** dp=0;
	dp = new ll*[n+1];
	rep(i,0,n+1)
		rep(j,0,sum+1)
			dp[i]=new ll[sum+1];
	rep(i,0,n+1)
		rep(j,0,sum+1)
			{
				if(i==0)
					dp[i][j]=false;
				if(j==0)
					dp[i][j]=true;
			}
	

	rep(i,1,n+1){
		rep(j,1,sum+1){
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	return dp;
}

int main(){
    
	tin{
		ll n;
		cin>>n;
		ll arr[n];
		ll s=0;
		rep(i,0,n) cin>>arr[i],s+=arr[i];

		// ll** dp = solve(arr,n,s);

		ll dp[n+1][s+1];
		rep(i,0,n+1)
			rep(j,0,s+1){
				if(i==0)
					dp[i][j]=false;
				if(j==0)
					dp[i][j]=true;
			}
		rep(i,1,n+1){
			rep(j,1,s+1){
				if(i==0)
					{
						dp[i][j]=false;
						// continue;
					}
				if(j==0){
						dp[i][j]=true;
						// continue;
					}
				if(arr[i-1]<=j && i && j)
					dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
				else if(arr[i-1]>j && i && j)
					dp[i][j]=dp[i-1][j];
			}
		}


		// cout<<dp[0][3];
		ll ans=0;
		rep(i,1,s+1)
			if(dp[n][i])
				ans+=i;

		cout<<ans<<endl;


	}
    
}