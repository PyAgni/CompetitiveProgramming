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
    
	tin{
		ll n;
		cin>>n;

		vector<pair<ll,ll> > pc;

		rep(i,0,n){
			ll a,b;
			cin>>a>>b;
			pc.pb(mp(a,b));
		}
		
		// rep(i,0,n){
		// 	cout<<pc[i].ff<<" "<<pc[i].ss<<endl;
		// }

		bool f=true;
		if(n==1){
			if(pc[0].ss>pc[0].ff){
			cout<<"NO"<<"\n";
				f=false;
				// break;
		}
		}
		for(int i=0;i<n && f==true;i++){
			if(pc[i].ss>pc[i].ff){
				// cout<<i<<" "<<pc[i].ff<<" "<<pc[i].ss<<endl;
				cout<<"NO"<<"\n";
				f=false;
				break;
			}
			rep(j,i+1,n){
				if((pc[j].ss-pc[i].ss)>(pc[j].ff-pc[i].ff)){
					cout<<"NO"<<"\n";
					f=false;
					break;
				}
				if(pc[j].ss<pc[i].ss){
					cout<<"NO"<<"\n";
				f=false;
				break;
				}
				if(pc[j].ff<pc[i].ff){
					cout<<"NO"<<"\n";
				f=false;
				break;
				}
			}
		}
	// rep(i,1,n){
	// 	if(pc[i].ss>pc[i].ff){
	// 		cout<<"NO"<<"\n";
	// 			f=false;
	// 			break;
	// 	}
	// 	if(pc[i].ss<pc[i-1].ss)
	// 	{
	// 		cout<<"NO"<<"\n";
	// 			f=false;
	// 			break;
	// 	}

	// 	if(pc[i].ff<pc[i-1].ff){
	// 		cout<<"NO"<<"\n";
	// 			f=false;
	// 			break;
	// 	}

	// 	if(pc[i].ss>pc[i-1].ss){
	// 		ll d=pc[i].ss,b=pc[i-1].ss;
	// 		ll a=pc[i-1].ff,c=pc[i].ff;

	// 		if(d-b > c-a){
	// 			cout<<"NO"<<"\n";
	// 			f=false;
	// 			break;
	// 		}
	// 	}
	// }
	if(f)
		cout<<"YES\n";
    }
}
