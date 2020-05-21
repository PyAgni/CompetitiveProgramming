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

int main(){
    
	ll n,l,r,x;
	cin>>n>>l>>r>>x;
	int c[n];
	rep(i,0,n) cin>>c[i];

	int ans=0;
	for(int mask=0;mask<=(1<<n);mask++){
		vector<int> diff;
		int total_diff=0;
		for(int i=0;i<n;i++){
			if(mask & (1<<i)){
				total_diff+=c[i];
				diff.pb(c[i]);
			}
		}
		sort(diff.begin(),diff.end());
		if(total_diff>=l && total_diff<=r && (diff[diff.size()-1]-diff[0])>=x)
			ans++;
	}
	cout<<ans;
    
}
