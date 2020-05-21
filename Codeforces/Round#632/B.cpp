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
		ll a[n],b[n];
		bool neg=false,zero=false,pos=false;
		ll ctr0=0,ctr1=0,ctr_1=0;
		rep(i,0,n) {
			cin>>a[i];
			if(a[i]==0)
				ctr0++;
			else if(a[i]<0)
				ctr_1++;
			else
				ctr1++;
		}
		rep(i,0,n) cin>>b[i];


		// rep(i,0,n){
		// 	if(a[i]==1 && i<n-1){
		// 		pos1[i+1]++;
		// 	}
		// 	if(a[i]==-1 && i<n-1){
		// 		neg1[i+1]++;
		// 	}
		// }

		bool f=true;
		rep(i,0,n){
			
			if(b[i]!=a[i]){if(b[i]==0)
						{
							if(a[i]<0 && !pos){
								f=false;
								break;
							}
							else if(a[i]>0 && !neg){
								f=false;
								break;
							}
							// f=false;
							// break;
						}
						// else if(b[i]>0 && a[i]==0)
						// {
						// 	f=false;
						// 	break;
						// }
						if(b[i]>0){
							if(a[i]==0 && !pos)
								{
									f=false;
									break;
								}
							if(a[i]==1 && !pos){
								f=false;
								break;
							}
							if(a[i]==-1 && !pos){
								f=false;
								break;
							}
			
						}
						if(b[i]<0){
							if(a[i]==0 && !neg){
								f=false;
								break;
							}
							else if(a[i]==1 && !neg){
								f=false;
								break;
							}
							else if(a[i]==-1 && !neg){
								f=false;
								break;
							}
						}
					}
					if(a[i]==-1)
				neg=true;
			if(a[i]==1)
				pos=true;

		}
		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    
}
