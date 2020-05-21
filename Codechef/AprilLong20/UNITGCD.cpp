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
	fio;
    // clock_t start,end;
    // start=clock();
	tin{
		ll n;
		cin>>n;

		if(n==1){
			cout<<1<<"\n";
			cout<<1<<" "<<1<<"\n";
			continue;
		}
		if(n&1){
			cout<<n/2<<"\n";
			cout<<3<<" "<<n-2<<" "<<n-1<<" "<<n<<"\n";

			n-=3;
			rep(i,0,n/2)
				cout<<2<<" "<<2*i+1<<" "<<2*i+2<<"\n";

		}
		else{
			cout<<n/2<<"\n";
			rep(i,0,n/2)
				cout<<2<<" "<<2*i+1<<" "<<2*i+2<<"\n";
		}
	}
	// end = clock();
	// double time=double(end-start)/ double(CLOCKS_PER_SEC); 
	// cout<<fixed;
	// cout<<time<<setprecision(5);
    
}
