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
    
	tin{int n,x;
		cin>>n>>x;
		int arr[n];
		int vis[10001]={0};
		rep(i,0,n) {
			cin>>arr[i];
			if(!vis[arr[i]])
				vis[arr[i]]++;
		}
		int ans=0;
		int i;
		sort(arr,arr+n);
		int maxx=arr[n-1];
		for(i=1;i<maxx,x>0;i++){
			if(!vis[i])
				{
					ans++;	
					x--;
					// cout<<i<<" ";
					vis[i]++;
	
				}
		}
		i--;
		rep(j,0,n){
			if(i+1 == arr[j])
				i++;
		}
		// rep(k,1,1001){
		// 	if(!vis[k]){
		// 		rep(j,0,n){
		// 			if()
		// 		}
		// 	}
		// }

		cout<<i<<endl;
	}
    
}
