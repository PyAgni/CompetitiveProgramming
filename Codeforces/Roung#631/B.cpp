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

// bool allVis(ll arr[],int siz){
	
// 	rep(i,0,siz){

// 	}
// }

bool check(ll arr[],ll partition,ll n){

	ll vis[200001]={0},vis1[200001]={0};
	ll s1=0,s2=0;

	rep(i,0,partition+1){
		vis[arr[i]]++;
	}

	rep(i,partition+1,n){
		vis1[arr[i]]++;
	}
	repp(i,1,partition+1){
		if(!vis[i])
			return false;
	}
	repp(i,1,n-partition-1){
		if(!vis1[i])
			return false;
	}

	return true;

}

int main(){
    
	tin{
		ll n;
		cin>>n;
		ll arr[n];
		rep(i,0,n) cin>>arr[i];

		int ans=0;
		bool a=false,b=false;

		vector<int> v;
		// for(ll i=0;i<n;i++){
		// 	if(arr[i]<= i+1){
		// 		if(check(arr,i,n))
		// 				{	
		// 					// cout<<"pp";
		// 					v.push_back(i+1);
		// 					// break;
		// 				}}
		// }


		ll vis[200001]={0},vis1[200001]={0};
		ll i;
		for(i=0;i<n;i++){
			// if(arr[i]>i+1) break;
			if(vis[arr[i]]) break;
			if(!vis[arr[i]]){
				vis[arr[i]]++;
			}
		}

		ll j;
		for(j=n-1;j>=0;j--){
			// if(arr[j]>j+1) break;
			if(vis1[arr[j]]) break;
			if(!vis1[arr[j]]){
				vis1[arr[j]]++;
			}
		}

		cout<<i-1<<" "<<j+1<<endl;
		bool f=false;
		if(check(arr,i-1,n))
			{	
				f=true;
				v.push_back(i);
			}
		{
			if(check(arr,j,n))
				v.pb(j+1);
		}
		cout<<v.size()<<endl;
		if(v.size()){
			rep(i,0,v.size())
			cout<<v[i]<<" "<<n-v[i]<<endl;
		}

	}
    
}
