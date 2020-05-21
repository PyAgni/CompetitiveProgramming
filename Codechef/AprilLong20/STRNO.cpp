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


ll solve1(ll n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
  
            else
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 


ll primeFactors(ll n){
	set<ll> s;
	ll ctr=0;
	while(n%2==0){
		s.insert(2);
		ctr++;
		n/=2;
	}

	for(int i=3;i<=sqrt(n);i+=2){
		while(n%i ==0){
			s.insert(i);
			ctr++;
			n/=i;
		}
	}
	if(n>2)
		{
			s.insert(n);
			ctr++;
		}

	return ctr;
}


int main(){
    
	tin{
		ll x,k;
		cin>>x>>k;

		ll s = primeFactors(x);
		// cout<<s<<endl;
		if(s<k)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	// cout<<"total primeF Number\n";
	// rep(i,2,10000){
	// 	cout<<solve1(i)<<"\t"<<primeFactors(i)<<"\t"<<i<<endl;
	// }
    
}
