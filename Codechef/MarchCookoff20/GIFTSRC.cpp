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



int main(){
    
    tin{
    	ll n;
    	cin>>n;
    	string s,s1="";
    	cin>>s;
    	char curr=s[0];
    	s1+=curr;
    	rep(i,1,n){

    		

    		if(s[i]=='L' || s[i]=='R')
    			if(curr=='D' || curr=='U')
    				s1+=s[i];
    		if(s[i]=='U' || s[i]=='D')
    			if(curr=='R' || curr=='L')
    				s1+=s[i];
    		curr=s[i];
    		// cout<<i<<" "<<curr<<" ";

    	}
    	// cout<<endl;
    	// cout<<s1<<endl;
    	ll x=0,y=0;
    	rep(i,0,s1.length())
    	{
    		if(s1[i]=='L')
    			x-=1;
    		if(s1[i]=='R')
    			x+=1;
    		if(s1[i]=='U')
    			y+=1;
    		if(s1[i]=='D')
    			y-=1;
    	}

    	cout<<x<<" "<<y<<"\n";
    }

	
    
}
