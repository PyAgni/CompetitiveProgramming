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

// -------------------------------------------------------------------------------- //



int main(){
    
	tin{
		ll n;
		cin>>n;
		ll arr[n];
		rep(i,0,n) cin>>arr[i];

		ll neg=0,pos=0,curr,res=0;
		bool p;
		curr=arr[0];
		if(curr<0)
			neg=curr,p=0;
		else
			pos=curr,p=1;
		res+=curr;
		rep(i,1,n){
			if(arr[i]<0){
				if(p){
					res+=arr[i];
					neg=arr[i];
					p=0;
					// cout<<"in1 "<<i<<"\n";
					continue;
				}
				if(neg==0){
					res+=arr[i];
					neg=arr[i];
					p=0;
					continue;
				}
				else if(arr[i]>neg)
				{
					res+=(arr[i]-neg);
					neg=arr[i];
					p=0;
					// cout<<"in2 "<<i<<"\n";
				}

			}
			if(arr[i]>0){
				if(!p){
					res+=arr[i];
					p=1;
					pos=arr[i];
					// cout<<"ip1 "<<i<<endl;
					continue;
				}
				if(arr[i]>pos){
					res+=(arr[i]-pos);
					pos=arr[i];
					p=1;
					// cout<<"ip2 "<<i<<"\n";
				}
			}
		}
		cout<<res<<"\n";

	}
    
}
