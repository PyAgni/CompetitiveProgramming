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
    
	int a,b;
	cin>>a>>b;
	bool f=true;
	vector<int>v;
	int B=b;
	while(a!=b){
		if(b<=0)
			break;
		if(b%2==0){
			b/=2;
			v.pb(b);
		}
		else{
			if(b%10 != 1){
				cout<<"NO";
				return 0;
			}
			b--;
			b/=10;
			v.pb(b);
		}
	}
	if(a!=b){
		cout<<"NO";
		return 0;
	}
	reverse(v.begin(), v.end());
	cout<<"YES"<<endl<<v.size()+1<<endl;	
	rep(i,0,v.size())
		cout<<v[i]<<" ";
	cout<<B;    
}
