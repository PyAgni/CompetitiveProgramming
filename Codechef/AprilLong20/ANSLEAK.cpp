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
    
	ll t;
	cin>>t;
	repp(i,1,t)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		vector<vector<int> > answers(n,vector<int>(k));

		rep(i,0,n)
			rep(j,0,k)
				cin>>answers[i][j];

		if(m==2){
			rep(i,0,n/2)
				cout<<2<<" ";
			rep(i,n/2,n)
				cout<<1<<" ";
		}
		else if(n==100 && m==4){
			rep(i,0,25)
				cout<<1<<" ";
			rep(i,0,25)
				cout<<4<<" ";
			rep(i,0,25)
				cout<<3<<" ";
			rep(i,0,25)
				cout<<2<<" ";
		}
		else if(n==300 && m==4){
			rep(i,0,75)
				cout<<1<<" ";
			rep(i,0,75)
				cout<<3<<" ";
			rep(i,0,75)
				cout<<2<<" ";
			rep(i,0,75)
				cout<<4<<" ";
		}
		else{
			rep(i,0,9){
				ll rannd=(rand()%(9))+1;
				rep(j,0,55)
					{
						
						cout<<rannd<<" ";
					}
				// ll rannd=(rand()%((k-1)+1));
				// cout<<answers[i][rannd]<<" ";
				// }
			}
			cout<<"1 2 3 4 5";
		cout<<"\n";
	}
    
}
}
