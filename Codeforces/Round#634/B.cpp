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
// #define mod 1e9+7
// #define N 100005

// ll qpow (ll n, ll m) {
// 	ll ret = 1;
// 	while (m) {
// 		if (m & 1) ret = ret * n % mod;
// 		n = n * n % mod;
// 		m >>= 1;
// 	}
// 	return ret;
// }
// ll inv (ll a) {
// 	return qpow(a, mod - 2);
// }



int main(){
    
	tin{
		ll n,a,b;
		cin>>n>>a>>b;

		ll chars[27];
		repp(i,1,26)
			chars[i]=i+96;
		// cout<<char(chars[3]);

		string s="";
		rep(i,0,b)
			s+=chars[i+1];

		if(a==1){
			for(int i=0,j=0;i<n;i++){
				cout<<char(chars[j+1]);
				if(j==25)
					j=0;
				else
					j++;
			}
			cout<<"\n";
			continue;
		}

		// cout<<s;
		string ans="";
		for(int i=0,j=0;i<n;i++){
			ans+=s[j];
			if(j==b-1)
				j=0;
			else
				j++;
		}
		cout<<ans<<"\n";



	}
    
}
	